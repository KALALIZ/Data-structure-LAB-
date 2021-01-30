#include <iostream>
#include <string>
#include <array>
#include <random>
#include <algorithm>
using namespace std;

struct RandomGenerator {
	RandomGenerator(const size_t min, const size_t max) : dist(min, max) {}
	random_device rd;
	uniform_int_distribution<size_t> dist;
	unsigned operator()() { return dist(rd); }
};

struct Gallow {
	void Draw() const
	{
		cout<<(" ________\n"
			"|        |\n"
			"|       %c %c\n"
			"|       %c%c%c\n"
			"|       %c %c\n"
			"|\n"
			"|\n", body[0], body[1], body[2], body[3],
		    	body[4], body[5], body[6]);
	}

	bool Increment()
	{
		switch (++errors) {
		case 6: body[6] = '\\'; break;
		case 5: body[5] = '/'; break;
		case 4: body[4] = '\\'; break;
		case 3: body[3] = '|'; break;
		case 2: body[2] = '/'; break;
		case 1: body[0] = '(', body[1] = ')'; break;
		}
		return errors < 6;
	}

	char body[7] { '\0' };
	int errors { 0 };
};

struct Game {
	void Draw() const
	{
		#ifdef _WIN32
		std::system("cls");
		#else
		std::system("clear");
		#endif	
		gallow.Draw();
		std::for_each(guess.begin(), guess.end(), [](const char c) { std::printf("%c ", c); });
		std::putchar('\n');
	}

	bool Update()
	{
		std::printf("Enter a letter: ");
		const char letter = std::tolower(std::getchar());
		while (std::getchar() != '\n') {}
		bool found = false;

		for (size_t i = 0; i < word.size(); ++i) {
			if (word[i] == letter) {
				guess[i] = letter;
				found = true;
			}
		}

		const auto end_game = [this](const char* msg) {
			Draw();
			std::puts(msg);
			return false;
		};

		if (not found and not gallow.Increment())
			return end_game("\n#### you lose! ####\n");
		else if (found and word == guess)
			return end_game("\n#### you win! ####\n");

		return true;
	}

	RandomGenerator rand_gen { 0, words.size() - 1 };
	const std::string word { words[rand_gen()] };
	std::string guess { std::string().insert(0, word.size(), '_') };
	Gallow gallow;
	static const std::array<const std::string, 5 > words;
};

const std::array < const std::string, 5 > Game::words{
	{"control", "television", "computer", "medicine", "corona"}};

int main()
{
	Game game;
	do {
		game.Draw();
	} while (game.Update());
	return EXIT_SUCCESS;
}
