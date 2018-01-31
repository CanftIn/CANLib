#pragma once
#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include <new>
#include <cstdlib>

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
			return (((bytes)+_ALIGN - 1) / _ALIGN - 1);
		}

		static size_t ROUND_UP(size_t bytes)
		{
			return (((bytes)+_ALIGN - 1) & ~(_ALIGN - 1));
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

	char *Alloc::start_free = 0;
	char *Alloc::end_free = 0;
	size_t Alloc::heap_size = 0;

	Alloc::obj* volatile Alloc::free_list[_NFREE_LISTS] =
	{
		nullptr,nullptr,nullptr,nullptr,
		nullptr,nullptr,nullptr,nullptr,
		nullptr,nullptr,nullptr,nullptr,
		nullptr,nullptr,nullptr,nullptr
	};

	/*
	//TODO
	void* Alloc::allocate(size_t bytes)
	{
		if (bytes > _MAX_BYTES)
		{
			return Malloc_Allocator::allocate(bytes);
		}
		size_t index = FREELIST_INDEX(bytes);
		obj *list = free_list[index];
		if (list)
		{
			free_list[index] = list->next;
			return list;
		}
		else
		{
			return Alloc::refill(ROUND_UP(bytes));
		}
	}
	*/

	class Malloc_Allocator
	{
	public:
		static void* allocate(size_t n)
		{
			void *result = malloc(n);
			if (result == nullptr)
				result == oom_malloc(n);
			return (result);
		}

		static void deallocate(void *p, size_t)
		{
			free(p);
		}

		static void* reallocate(void *p, size_t, size_t new_size)
		{
			void *result = realloc(p, new_size);
			if (result == nullptr)
				result = oom_realloc(p, new_size);
			return (result);
		}

		static void(*set_malloc_handler(void(*f)()))()
		{
			void(*old)() = malloc_allo_oom_handler;
			malloc_allo_oom_handler = f;
			return (old);
		}

	private:
		static void* oom_malloc(size_t);
		static void* oom_realloc(void*, size_t);
		static void(*malloc_allo_oom_handler)();
	};

	void(*Malloc_Allocator::malloc_allo_oom_handler)() = nullptr;

	void* Malloc_Allocator::oom_malloc(size_t n)
	{
		void(*my_malloc_handler)();
		void *result;
		for (;;)
		{
			my_malloc_handler = malloc_allo_oom_handler;
			if (my_malloc_handler == nullptr)
				throw std::bad_alloc();
			(*my_malloc_handler)();
			result = malloc(n);
			if (result)
				return (result);
		}
	}

	void* Malloc_Allocator::oom_realloc(void *p, size_t n)
	{
		void(*my_malloc_handler)();
		void *result;
		for (;;)
		{
			my_malloc_handler = malloc_allo_oom_handler;
			if (my_malloc_handler == nullptr)
				throw std::bad_alloc();
			(*my_malloc_handler)();
			result = realloc(p, n);
			if (result)
				return (result);
		}
	}
}


#endif // !_ALLOCATOR_H_
