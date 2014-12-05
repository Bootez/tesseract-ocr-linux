CXX=g++
LDFLAGS=-ltesseract -llept
TARGET=BasicExample                         \
	   GetComponentImagesExample            \
	   ResultIteratorExample                \
	   OrientationAndScriptDetectionExample \
	   IteratorExample

RM=rm -f

all:$(TARGET)

clean: 
	$(RM) $(TARGET)

