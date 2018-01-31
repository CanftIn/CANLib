#pragma once
#ifndef _ITERATOR_BASE_H_
#define _ITERATOR_BASE_H_

namespace Can
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<typename category, typename T>
	struct iterator
	{
		using iterator_category = category;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		using distance = Can::ptrdiff_t;
	};

}



#endif