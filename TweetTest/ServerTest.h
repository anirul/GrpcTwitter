#pragma once

#include <gtest/gtest.h>
#include "../TweetLib/Storage.h"
#include "../TweetLib/Server.h"

namespace test {

	class ServerTest : public testing::Test
	{
	public:
		ServerTest() = default;

	protected:
		std::shared_ptr<tweet::Storage> storage_ = nullptr;
		std::shared_ptr<tweet::Server> server_ = nullptr;
	};

} // End namespace test.
