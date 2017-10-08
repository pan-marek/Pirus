#include "catch.hpp"

#include "Splitter.h"
#include "Fragment.h"
#include <vector>

TEST_CASE("Splitter", "[splitter]")
{
	SECTION("simple")
	{
		auto str = "<a>TEXT</a>";
		Pirus::Splitter s;
		s(str);

		auto& fragments = s.get_fragments();
		REQUIRE(fragments.size() == 3);
		
		Pirus::Fragment a1;
		a1.level = 0;
		a1.type = Pirus::FRAGMENT_TYPE::TAG;
		a1.value = "a";

		Pirus::Fragment text;
		text.level = 1;
		text.type = Pirus::FRAGMENT_TYPE::TEXT;
		text.value = "TEXT";

		Pirus::Fragment a2;
		a2.level = 0;
		a2.type = Pirus::FRAGMENT_TYPE::CLOSE_TAG;
		a2.value = "a";

		std::vector<Pirus::Fragment> correct_fragments = {a1,text,a2};

		REQUIRE(fragments == correct_fragments);
	}

	SECTION("Simple with attribute")
	{
		auto str = "<a href=\"index.html\">TEXT</a>";
		Pirus::Splitter s;
		s(str);

		auto& fragments = s.get_fragments();
		REQUIRE(fragments.size() == 5);

		Pirus::Fragment a1;
		a1.level = 0;
		a1.type = Pirus::FRAGMENT_TYPE::TAG;
		a1.value = "a";

		Pirus::Fragment atr_name;
		atr_name.level = 0;
		atr_name.type = Pirus::FRAGMENT_TYPE::ATTRIBUTE_NAME;
		atr_name.value = "href";

		Pirus::Fragment atr_value;
		atr_value.level = 0;
		atr_value.type = Pirus::FRAGMENT_TYPE::ATTRIBUTE_VALUE;
		atr_value.value = "index.html";

		Pirus::Fragment text;
		text.level = 1;
		text.type = Pirus::FRAGMENT_TYPE::TEXT;
		text.value = "TEXT";

		Pirus::Fragment a2;
		a2.level = 0;
		a2.type = Pirus::FRAGMENT_TYPE::CLOSE_TAG;
		a2.value = "a";

		std::vector<Pirus::Fragment> correct_fragments = {a1,atr_name,atr_value,text,a2};

		REQUIRE(fragments == correct_fragments);
	}
}