#include "text_painter.h"

TextPainter::TextPainter(const QImage &image) : original_image_(image), editing_image_(image),
                                                painter_(&editing_image_) {}

void TextPainter::DrawText(const TextPainter::TextTemplate &text, QPointF position) {
    painter_.setFont(text.font);
    QFont font;
    painter_.setPen(text.color);
    painter_.drawText(position, text.content);
}

void TextPainter::SetImage(const QImage &image) {
    editing_image_ = original_image_ = image;
}

void TextPainter::Clear() {
    editing_image_ = original_image_;
}

QPixmap TextPainter::GetResultPixmap() {
    return QPixmap::fromImage(editing_image_);
}

QImage TextPainter::GetResultImage() {
    return editing_image_;
}


/*
 * TODO(Pavel): Перенести в mainwinow для подготовки изображения, отвечает за центрирование объекта
 * buff.setX(settings.point[i].x()
 *                   - (((items[i].length()) * 0.25) * (settings.font[i].pixelSize()))
 *                   );
 */
