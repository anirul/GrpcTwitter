#pragma once

#include <memory>
#include <grpcpp/channel.h>
#include "../GrpcLib/Tweet.pb.h"
#include "../GrpcLib/Tweet.grpc.pb.h"

namespace tweet {

	class Client
	{
	public:
		Client(std::shared_ptr<grpc::Channel> channel);
		grpc::Status Tweet(
			const proto::TweetIn in, 
			std::shared_ptr<proto::TweetOut> out);
		grpc::Status Follow(
			const proto::FollowIn in,
			std::shared_ptr<proto::FollowOut> out);
		grpc::Status Show(
			const proto::ShowIn in,
			std::shared_ptr<proto::ShowOut> out);
		grpc::Status Login(
			const proto::LoginIn in,
			std::shared_ptr<proto::LoginOut> out);
		grpc::Status Logout(
			const proto::LogoutIn in,
			std::shared_ptr<proto::LogoutOut> out);
		grpc::Status Register(
			const proto::RegisterIn in,
			std::shared_ptr<proto::RegisterOut> out);
	};

} // End namespace tweet
