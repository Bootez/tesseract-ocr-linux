#include <tesseract/baseapi.h>
#include <tesseract/resultiterator.h>
#include <leptonica/allheaders.h>

int main(int argc, const char *argv[])
{
    const char* inputfile = "eurotext.tif";
    tesseract::Orientation orientation;
    tesseract::WritingDirection direction;
    tesseract::TextlineOrder order;
    float deskew_angle;

    PIX *image = pixRead(inputfile);
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    api->Init("/usr/src/tesseract-3.02/", "eng");
    api->SetPageSegMode(tesseract::PSM_AUTO_OSD);
    api->SetImage(image);
    api->Recognize(0);

    tesseract::PageIterator* it =  api->AnalyseLayout();
    it->Orientation(&orientation, &direction, &order, &deskew_angle);
    printf("Orientation: %d;\nWritingDirection: %d\nTextlineOrder: %d\n" \
           "Deskew angle: %.4f\n",
           orientation, direction, order, deskew_angle);

    return 0;
}
