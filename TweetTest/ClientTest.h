#pragma once

#include <gtest/gtest.h>
#include "../TweetLib/Client.h"

namespace test {

	class ClientTest : public testing::Test
	{
	public:
		ClientTest() = default;

	protected:
		std::shared_ptr<tweet::Client> client_ = nullptr;
	};

} // End namespace test.
