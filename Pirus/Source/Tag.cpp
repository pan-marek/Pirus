#include "..\Tag.h"

#include <algorithm>

Pirus::Tag::Tag(const Pirus::text& name, Pirus::ALLOW_CHILDREN allow_children)
	: name{name}, allow_children{allow_children}
{}

const Pirus::text& Pirus::Tag::get_name() const
{
	return name;
}

std::optional<Pirus::text> Pirus::Tag::get_attribute(const Pirus::text& attribute_name) const
{
	auto find = std::find_if(std::cbegin(attributes), 
							std::cend(attributes), 
							[&attribute_name](const auto& attribute){ return attribute.first == attribute_name;});
	
	if(find != std::cend(attributes))
		return find->second;
	return std::nullopt;
}

void Pirus::Tag::set_attribute(const Pirus::text& attribute_name, const Pirus::text& value)
{
	attributes[attribute_name] = value;
}
