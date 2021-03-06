#pragma once

#include <sstream>
#include <utility>
#include <stack>

#include "Definitions.h"
#include "Tag.h"

namespace Pirus
{
	class TagFormatter
	{
	public:
		TagFormatter(const Pirus::Tag& tag);
		
		void set_format_tag_name(Pirus::FORMAT_TEXT format_type);
		const Pirus::text& to_text();

		virtual ~TagFormatter() = default;

	private:
		void generate_output(const Pirus::Tag& tag, unsigned level = 0);
		void generate_output(const Pirus::text& tag, unsigned level = 0);
		void build_new_line_and_indetions(unsigned level);
		void build_front(const Pirus::Tag& tag);
		void build_attributes(const Pirus::Tag& tag);
		void build_end_of_single_tag();
		void build_close_of_container_tag();
		void build_children_of_tag(const Pirus::Tag& tag, unsigned level);
		void build_end_of_container_tag(const Pirus::Tag& tag);
		Pirus::text transform_by(std::wstring_view tag_name, Pirus::FORMAT_TEXT format_type);
		void clear_buffor();

		const Pirus::Tag& tag_to_format;

		Pirus::text indention;
		Pirus::text new_line;
		Pirus::text open_tag;
		Pirus::text close_tag;
		Pirus::text single_tag_close_mark;
		Pirus::text container_tag_close_mark;
		Pirus::text attribute_restraint_mark;

		Pirus::FORMAT_TEXT format_tag_name;
		Pirus::FORMAT_TEXT format_attribute_name;
		Pirus::FORMAT_TEXT format_attribute_value;

		Pirus::text generated_output;
		std::wstringstream builder;
	};

}
