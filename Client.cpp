#include "Prog.h"

std::string Client::GetResponce(std::string url) {
	try
	{
		boost::asio::io_context io;
		boost::asio::ip::tcp::resolver rlv(io);
		boost::asio::ip::tcp::socket socket(io);

		boost::asio::connect(socket, rlv.resolve(this->Api_string, "80"));

		boost::beast::http::request<boost::beast::http::string_body> req(boost::beast::http::verb::get, this->Api_Arguments + url, 11);

		req.set(boost::beast::http::field::host, this->Api_string);
		req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

		boost::beast::http::write(socket, req);

		std::string response;

		boost::beast::flat_buffer buffer;
		boost::beast::http::response< boost::beast::http::dynamic_body> res;
		boost::beast::http::read(socket, buffer, res);
		response = boost::beast::buffers_to_string(res.body().data());

		socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
		return response;
	}
	catch (std::exception const& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}