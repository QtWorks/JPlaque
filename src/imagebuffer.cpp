#include "imagebuffer.h"

ImageBuffer::ImageBuffer(){
    this->background01 = make_shared<QPixmap>();
    this->background01->load(":/images/arteria_background.png", "PNG");
}

shared_ptr<QPixmap> ImageBuffer::getImage(Image type){
    switch (type){
    case BACKGROUND_01: return this->background01;
    }
    return nullptr;
}
