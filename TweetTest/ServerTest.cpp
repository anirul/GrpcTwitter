#include "ServerTest.h"

namespace test {

	TEST_F(ServerTest, CreateServerTest)
	{
		ASSERT_FALSE(storage_);
		storage_ = std::make_shared<tweet::Storage>();
		ASSERT_TRUE(storage_);
		EXPECT_FALSE(server_);
		server_ = std::make_shared<tweet::Server>(storage_);
		EXPECT_TRUE(server_);
	}

	TEST_F(ServerTest, LoginServerTest)
	{
		ASSERT_FALSE(storage_);
		storage_ = std::make_shared<tweet::Storage>();
		ASSERT_TRUE(storage_);
		ASSERT_FALSE(server_);
		server_ = std::make_shared<tweet::Server>(storage_);
		ASSERT_TRUE(server_);
		{
			proto::LoginIn in{};
			proto::LoginOut out{};
			EXPECT_TRUE(server_->Login(&in, &out).ok());
		}
	}

} // End namespace test.
