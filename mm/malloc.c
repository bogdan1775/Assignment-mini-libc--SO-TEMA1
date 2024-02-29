// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size) {
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	if (ptr == MAP_FAILED)
		return NULL;

	mem_list_add(ptr, size);

	return ptr;
}

void *calloc(size_t nmemb, size_t size) {
	void *ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return NULL;

	memset(ptr, 0, nmemb * size);
	return ptr;
}

void free(void *ptr) {
	struct mem_list *iter;
	iter = mem_list_find(ptr);

	if (iter == NULL)
		return;

	munmap(iter->start, iter->len);
	mem_list_del(iter->start);
}

void *realloc(void *ptr, size_t size) {
	if (ptr == NULL)
		return malloc(size);

	struct mem_list *iter;
	iter = mem_list_find(ptr);

	if (iter == NULL)
		return NULL;

	void *new_ptr = mremap(ptr, iter->len, size, MAP_PRIVATE | MAP_ANONYMOUS);
	if (new_ptr == NULL)
		return NULL;

	mem_list_del(iter->start);
	mem_list_add(new_ptr, size);

	return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
	ptr = realloc(ptr, nmemb * size);
	return ptr;
}
