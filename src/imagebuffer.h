#ifndef IMAGEBUFFER_H
#define IMAGEBUFFER_H

#include <QPixmap>
#include <QString>
#include <memory>

using std::shared_ptr;
using std::make_shared;

namespace {
    const QString QSTR_BACKGROUND_01{":/image/arteria_background.png"};
}

class ImageBuffer final {
    shared_ptr<QPixmap> background01;

    ImageBuffer();
    ~ImageBuffer()= default;
    ImageBuffer(const ImageBuffer&)= delete;
    ImageBuffer& operator=(const ImageBuffer&)= delete;

public:
    enum Image{
        BACKGROUND_01
    };
    static ImageBuffer& getInstance(){
        static ImageBuffer instance{};
        return instance;
    }
    shared_ptr<QPixmap> getImage(Image);
};

#endif // IMAGEBUFFER_H
