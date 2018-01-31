#pragma once
#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

namespace Can
{
	enum { _ALIGN = 8 };
	enum { _MAX_BYTES = 128 };
	enum { _NFREE_LISTS = _MAX_BYTES / _ALIGN };

	class Alloc
	{
	private:
		union obj
		{
			union obj *free_list_link;
			char client_data[1];
		};

	private:
		static obj* volatile free_list[_NFREE_LISTS];

		static size_t FREELIST_INDEX(size_t bytes)
		{
			return (((bytes) + _ALIGN - 1) / _ALIGN - 1);
		}

		static size_t ROUND_UP(size_t bytes)
		{
			return (((bytes) + _ALIGN - 1) & ~(_ALIGN - 1));
		}

		static void refill(size_t n);

		static char* chunk_alloc(size_t size, int &nobjs);

		static char* start_free;
		
		static char* end_free;

		static size_t heap_size;

	public:
		static void* allocate(size_t n);
		static void deallocate(void *p, size_t n);
		static void* reallocate(void *p, size_t old_sz, size_t new_sz);
	};

	class Allocator
	{

	};
}


#endif // !_ALLOCATOR_H_
