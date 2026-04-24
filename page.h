/*
The Page Cache manages up to 64 Page Frames in memory. Every structure lives 
inside pages. A page is a 4KB block of bytes and is addressed by an unsigned 
32-bit page ID. Page 0 is reserved for the database header.
*/

#ifndef __PAGE_H__
#define __PAGE_H__

#include <stdint.h>
#include <stdbool.h>

typedef struct PageCache PageCache;

typedef struct PageFrame PageFrame;

PageCache* page_cache_open(int fd);
void page_cache_close(PageCache* cache);
PageFrame* page_pin(PageCache* cache, uint32_t page_id);
void page_unpin(PageCache* cache, PageFrame* frame, bool dirty);
PageFrame* page_alloc(PageCache* cache);
void page_flush(PageCache* cache, uint32_t page_id);
uint8_t* page_data(PageFrame* frame);

#endif /* __PAGE_H__ */