
#include <cstdint>
#include <algorithm>
#include <memory>

class PackageStream;

class BufferedReader {
 private:
  PackageStream *object;
  std::unique_ptr<char[]> buffer;

 public:
  int32_t positionOfPointer = 0, packLen = 0,
      bufferLenght = 0, lenghtOfPack = 0;
  explicit BufferedReader(PackageStream *stream) {
    this->object = stream;
    int32_t lenghtOfNewBuffer = object->PackageLen();
    buffer.reset(new char[lenghtOfNewBuffer]);
  }

  int32_t Read(char *output_buffer, int32_t buffer_len) {
    lenghtOfPack = 0;
    auto buffer_pos = buffer_len;
    while (true) {
      if (bufferLenght <= 0) {
        bufferLenght = object->ReadPackage(buffer.get());
        positionOfPointer = 0;
      }

      if ((bufferLenght > 0) && (lenghtOfPack < buffer_len)) {
        packLen = min<int32_t>(bufferLenght,
                               buffer_pos);

        memcpy(output_buffer + lenghtOfPack,
               buffer.get() + positionOfPointer,
               packLen);

        buffer_pos -= packLen;
        positionOfPointer += packLen;
        bufferLenght -= packLen;
        lenghtOfPack += packLen;

      } else {
        break;
      }
    }
    return lenghtOfPack;
  }
};
