#include <tesseract/baseapi.h>
#include <tesseract/resultiterator.h>
#include <leptonica/allheaders.h>

int main(int argc, const char *argv[])
{
    Pix *image = pixRead("/usr/src/tesseract-3.02/phototest.tif");
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    api->Init(NULL, "eng");
    api->SetImage(image);
    api->SetVariable("save_blob_choices", "T");
    api->SetRectangle(37, 228, 548, 31);
    api->Recognize(NULL);

    tesseract::ResultIterator* ri = api->GetIterator();
    tesseract::PageIteratorLevel level = tesseract::RIL_SYMBOL;
    if(ri != 0) {
        do {
            const char* symbol = ri->GetUTF8Text(level);
            float conf = ri->Confidence(level);
            if(symbol != 0) {
                printf("symbol %s, conf: %f", symbol, conf);
                bool indent = false;
                tesseract::ChoiceIterator ci(*ri);
                do {
                    if (indent) printf("\t\t ");
                    printf("\t- ");
                    const char* choice = ci.GetUTF8Text();
                    printf("%s conf: %f\n", choice, ci.Confidence());
                    indent = true;
                } while(ci.Next());
            }
            printf("---------------------------------------------\n");
            delete[] symbol;
        } while((ri->Next(level)));
    }
    return 0;
}
