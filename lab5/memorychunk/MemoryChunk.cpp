//
// Created by Zuzanna on 06.04.2018.
//

#include "MemoryChunk.h"

namespace memorychunk{


    MemoryChunk::MemoryChunk(size_t sz) {

    }

    int8_t *MemoryChunk::MemoryAt(size_t offset) const {
        return nullptr;
    }

    size_t MemoryChunk::ChunkSize() const {
        return 0;
    }

    MemoryChunk::~MemoryChunk() {

    }

    MemoryChunk::MemoryChunk(const MemoryChunk &tocopy) {

    }

    MemoryChunk::MemoryChunk(MemoryChunk &&tocopy) {

    }

    MemoryChunk &MemoryChunk::operator=(const MemoryChunk &tocopy) {
        if (this == &tocopy){
            return *this;
        }
        delete [] wsk_;

        size_ = tocopy.size_;
        wsk_ = new int8_t[size_];


    }
}
