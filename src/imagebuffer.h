#ifndef IMAGEBUFFER_H
#define IMAGEBUFFER_H

#include <QPixmap>
#include <QString>
#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;

namespace {
    const QString QSTR_BACKGROUND_01 {":/images/arteria_background.png"};
    const QString QSTR_BACKGROUND_02 {":/images/arteria_foreground.png"};
    const QString QSTR_NEBULAR       {":/images/arteria_fog.png"};
    const QString QSTR_PLAYER        {":/images/player.png"};
    const QString QSTR_ERYTHROCYTE   {":/images/bloodcell.png"};
}

class ImageBuffer final {
    shared_ptr<QPixmap> background01;
    shared_ptr<QPixmap> background02;
    shared_ptr<QPixmap> nebular;
    shared_ptr<QPixmap> player;
    shared_ptr<QPixmap> erythrocyte;

    ImageBuffer();
    ~ImageBuffer()= default;
    ImageBuffer(const ImageBuffer&)= delete;
    ImageBuffer& operator=(const ImageBuffer&)= delete;

public:
    enum Image{
        BACKGROUND_01, BACKGROUND_02, NEBULAR, PLAYER, ERYTHROCYTE
    };
    static ImageBuffer& getInstance(){
        static ImageBuffer instance;
        return instance;
    }
    shared_ptr<QPixmap> getImage(Image);
};

#endif // IMAGEBUFFER_H
