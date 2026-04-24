#include "page.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define PAGE_SIZE 4096
#define NUM_FRAMES 64

struct PageCache {
    int fd;
    uint8_t *slab;
    PageFrame *frames;
    int clock_hand;
};

struct PageFrame {
    uint32_t page_id;
    uint8_t *data;
    bool dirty;
    int pin_count;
    bool ref_bit;
};

PageCache* page_cache_open(int fd) {

}

void page_cache_close(PageCache* cache){

}

PageFrame* page_pin(PageCache* cache, uint32_t page_id){

}

void page_unpin(PageCache* cache, PageFrame* frame, bool dirty){

}

PageFrame* page_alloc(PageCache* cache){

}

void page_flush(PageCache* cache, uint32_t page_id){

}

uint8_t* page_data(PageFrame* frame){

}