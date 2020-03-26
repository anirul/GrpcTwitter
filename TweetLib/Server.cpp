#include "Server.h"

namespace tweet {

	grpc::Status Server::Tweet(
		grpc::ServerContext* context, 
		const proto::TweetIn* request, 
		proto::TweetOut* response)
	{
		std::string peer = context->peer();
		if (!storage_->Tweet(peer, request->content()))
		{
			response->set_error(true);
		}
		else
		{
			response->set_error(false);
		}
		return grpc::Status::OK;
	}

	grpc::Status Server::Follow(
		grpc::ServerContext* context, 
		const proto::FollowIn* request, 
		proto::FollowOut* response)
	{
		std::string peer = context->peer();
		if (!storage_->Follow(peer, request->name()))
		{
			response->set_error(true);
		}
		else
		{
			response->set_error(false);
		}
		return grpc::Status::OK;
	}

	grpc::Status Server::Show(
		grpc::ServerContext* context, 
		const proto::ShowIn* request, 
		proto::ShowOut* response)
	{
		std::string peer = context->peer();
		auto values = storage_->Show(peer, request->user());
		for (const auto& value : values)
		{
			proto::TweetIn ti{};
			ti.set_user(value.name);
			ti.set_time(value.time);
			ti.set_content(value.text);
			*response->add_tweets() = ti;
		}
		if (values.empty())
		{
			response->set_error(true);
		}
		else
		{
			response->set_error(false);
		}
		return grpc::Status::OK;

	}

	grpc::Status Server::Login(
		grpc::ServerContext* context, 
		const proto::LoginIn* request, 
		proto::LoginOut* response)
	{
		std::string peer = context->peer();
		if (!storage_->Login(peer, request->user(), request->pass()))
		{
			response->set_error(true);
		}
		else
		{
			response->set_error(false);
		}
		return grpc::Status::OK;
	}

	grpc::Status Server::Logout(
		grpc::ServerContext* context, 
		const proto::LogoutIn* request, 
		proto::LogoutOut* response)
	{
		std::string peer = context->peer();
		if (!storage_->Logout(peer))
		{
			response->set_error(true);
		}
		else
		{
			response->set_error(false);
		}
		return grpc::Status::OK;
	}

	grpc::Status Server::Register(
		grpc::ServerContext* context, 
		const proto::RegisterIn* request, 
		proto::RegisterOut* response)
	{
		std::string peer = context->peer();
		if (!storage_->Register(peer, request->name(), request->pass()))
		{
			response->set_error(true);
		}
		else
		{
			response->set_error(false);
		}
		return grpc::Status::OK;
	}

} // End namespace tweet.
