#include "imagebuffer.h"

ImageBuffer::ImageBuffer(){
    this->background01 = make_shared<QPixmap>();
    this->background01->load(QSTR_BACKGROUND_01);

    this->background02 = make_shared<QPixmap>();
    this->background02->load(QSTR_BACKGROUND_02);

    this->nebular = make_shared<QPixmap>();
    this->nebular->load(QSTR_NEBULAR);

    this->player = make_shared<QPixmap>();
    this->player->load(QSTR_PLAYER);

    this->erythrocyte = make_shared<QPixmap>();
    this->erythrocyte->load(QSTR_ERYTHROCYTE);

    this->leukocythe = make_shared<QPixmap>();
    this->leukocythe->load(QSTR_ERYTHROCYTE);

    this->seeker = make_shared<QPixmap>();
    this->seeker->load(QSTR_ERYTHROCYTE);
}

shared_ptr<QPixmap> ImageBuffer::getImage(Image type){
    switch (type){
    case BACKGROUND_01: return this->background01;
    case BACKGROUND_02: return this->background02;
    case NEBULAR:       return this->nebular;
    case PLAYER:        return this->player;
    case ERYTHROCYTE:   return this->erythrocyte;
    case LEUKOCYTHE:    return this->leukocythe;
    case SEEKER:        return this->seeker;
    }
    return nullptr;
}
