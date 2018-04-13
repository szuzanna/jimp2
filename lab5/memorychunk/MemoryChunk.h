//
// Created by Zuzanna on 06.04.2018.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H


#include <cstdint>
#include <algorithm>

namespace memorychunk {
    class MemoryChunk {
    public:
        MemoryChunk(size_t sz);

        int8_t *MemoryAt(size_t
                         offset) const;

        size_t ChunkSize() const;

        ~MemoryChunk();

        MemoryChunk(const MemoryChunk &tocopy);

        MemoryChunk(MemoryChunk &&tocopy);

        MemoryChunk&operator=(const MemoryChunk &tocopy);

        MemoryChunk&operator=(MemoryChunk &&tocopy);
    private:
        int8_t *wsk_;
        size_t size_;
    };
}

#endif //JIMP_EXERCISES_MEMORYCHUNK_H
