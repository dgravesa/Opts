/*
	Daniel Graves
	test_opts.cpp
*/

#include "Opts.hpp"

static Option options[] =  
{
	{ "help", 'h', NO_ARG, NULL },
	{ "verbose", 'v', NO_ARG, NULL },
	{ "sigmas", 's', REQUIRED_ARG, "set bandwidths for computation" },
	{ "shuffle", 'S', OPTIONAL_ARG, "perform data shuffling prior to computation with optional seed argument" },
	{ "output", 'o', REQUIRED_ARG, "set output directory" },
	{ NULL, 'x', NO_ARG, "this flag does not have a long option" },
	{ "what-an-egregiously-long-option-we-have-here", 'w', NO_ARG, "this flag pushes the limits of readability" },
	{ NULL, 'R', REQUIRED_ARG, "this flag does not have a long option but requires an argument" },
	{ NULL, 'O', OPTIONAL_ARG, "this flag does not have a long option but has an optional argument" },
	{ 0, 0, 0, 0 }
};

int main(int argc, char **argv)
{
	OptHandler opt_handler(options, argc, argv);

	char opt;
	std::string arg;

	// print specified options
	while (opt_handler.getOpt(opt, arg))
	{
		switch (opt)
		{
			case 'h':
				opt_handler.printUsage("usage: test_opts [-s SIGMAS] [file ...]");
				break;

			case 'v':
				std::cout << "this option prints verbose runtime information\n";
				break;

			case 's':
				std::cout << "this option sets the sigma value to " << arg << "\n";
				break;

			case 'S':
				std::cout << "this option sets the shuffling flag";
				if (!arg.empty()) std::cout << " with a seed value of " << arg;
				std::cout << "\n";
				break;

			case 'o':
				std::cout << "this option sets the output directory to '" << arg << "'\n";
				break;

			case 'x':
				std::cout << "this flag does nothing\n";
				break;

			case '?':
				std::cerr << "exiting with error...\n";
				return 1;

			default:
				break;
		};
	}

	// print specified non-opt arguments
	std::cout << "non-option arguments:";
	while (opt_handler.getNonOptArg(arg))
		std::cout << " " << arg;
	std::cout << "\n";

	return 0;
}

