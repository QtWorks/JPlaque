#include "imagebuffer.h"

ImageBuffer::ImageBuffer(){
    this->background01->load(QSTR_BACKGROUND_01);
}

shared_ptr<QPixmap> ImageBuffer::getImage(Image type){
    switch (type){
    case BACKGROUND_01: return this->background01;
    }
}
