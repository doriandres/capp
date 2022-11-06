#include <iostream>
#include <iomanip>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <cpprest/http_listener.h>
#include "MyMath/MyMath.h"

namespace myapp
{
	bool terminate{false};

	void on_terminate(int e)
	{
		terminate = true;
	}

	std::wstring get_time()
	{
		time_t now = time(0);
		utility::stringstream_t ss;
		ss << std::put_time(localtime(&now), L"%Y-%m-%dT%H:%S:%MZ");

		return ss.str();
	}

	void request_handler(web::http::http_request request)
	{
		auto time = get_time();
		std::wcout << "Received request at " << time << std::endl;

		web::json::value response;
		response[L"message"] = web::json::value::string(L"Hello World");
		response[L"result"] = web::json::value::number(mymath::add_with_10(5, 3));
		response[L"time"] = web::json::value::string(time);

		request.reply(web::http::status_codes::OK, response);
	}

	void run_server()
	{
		std::wstring server_base_address{L"http://localhost:3000"};

		web::http::experimental::listener::http_listener http_listener(server_base_address);

		http_listener.support(request_handler);

		std::cout << "Starting listener." << std::endl;
		http_listener.open().wait();
		std::wcout << "Listening on " << server_base_address << std::endl;

		signal(SIGINT, on_terminate);
		while (!terminate)
		{
			/* Keep program running as daemon */
		}

		std::cout << "Terminating HTTP listener." << std::endl;
		http_listener.close();
	}
}

int main()
{
	myapp::run_server();
	return 0;
}