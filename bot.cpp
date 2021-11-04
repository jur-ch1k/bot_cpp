#include <stdio.h>
#include <tgbot/tgbot.h>
#include <unistd.h>

//using namespace std

/*void put_info(char* text, name) {
	f = fopen("userZ.txt", "a+");
	fprintf(f, "User %s wrote: %s\n", message->chat->firstName.c_str(), message->text.c_str());
	fclose(f);
}*/

static int64_t my_chat = 926000463;

int main() {
	int count = 0;
	

	TgBot::Bot bot("2072288430:AAFNyiy3FNrPubAxs4Njpun479AIMZvS-kY");

	bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
		FILE* f;
		bot.getApi().sendMessage(message->chat->id, "Hi, " + message->chat->firstName + "!");

		//bot.getApi().sendMessage(my_chat, message->chat->firstName + " just wrote: " + message->text);

		f = fopen("userZ.txt", "a+");
		fprintf(f, "User %s used /start\n", message->chat->firstName.c_str());
		fclose(f);
		std::cout << message->chat->id;
		});

	bot.getEvents().onCommand("hi", [&bot](TgBot::Message::Ptr message) {
		FILE* f;
		bot.getApi().sendMessage(message->chat->id, "Hi, " + message->chat->firstName + "!" + " I'm just for fun. So try to have fun)");

		//bot.getApi().sendMessage(my_chat, message->chat->firstName + " just wrote: " + message->text);

		f = fopen("userZ.txt", "a+");
		fprintf(f, "User %s used /hi\n", message->chat->firstName.c_str());
		fclose(f);
		});

	bot.getEvents().onCommand("bb", [&bot](TgBot::Message::Ptr message) {
		FILE* f;
		bot.getApi().sendMessage(message->chat->id, "Good night<3");

		//bot.getApi().sendMessage(my_chat, message->chat->firstName + " just wrote: " + message->text);

		f = fopen("userZ.txt", "a+");
		fprintf(f, "User %s used /bb\n", message->chat->firstName.c_str());
		fclose(f);
		});

	bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
		std::cout << "\nUser " << message->chat->firstName << " wrote: " << message->text.c_str() << "\n\n";
		FILE* f;

		if (StringTools::startsWith(message->text, "/")) {
			return;
		}

		//std::cout << message->chat->username << '\n';
		bot.getApi().sendMessage(message->chat->id, "User "+ message->chat->firstName + " says: " + message->text);
		bot.getApi().forwardMessage(message->chat->id, message->chat->id, message->messageId);
		//bot.getApi().sendMessage(message->chat->id, "Go 1 na 1");

		//bot.getApi().sendMessage(my_chat, message->chat->firstName + " just wrote: " + message->text);

		f = fopen("userZ.txt", "a+");
		fprintf(f, "User %s wrote: %s\n", message->chat->firstName.c_str(), message->text.c_str());
		fclose(f);

		});

	/*bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
		FILE* f;

		if (StringTools::startsWith(message->text, "/")) {
			return;
		}
		//if (!StringTools::startsWith(message->chat->firstName, "Valery") && !StringTools::startsWith(message->chat->firstName, "Mike")&&!StringTools::startsWith(message->chat->firstName, "Кирилл")&&!StringTools::startsWith(message->chat->firstName, "jur_ch1k")){
		//    return;
		//}
		//std::cout << message->chat->username << '\n';
		bot.getApi().sendMessage(message->chat->id, "and\n");
		sleep(1);
		bot.getApi().sendMessage(message->chat->id, "and...");
		sleep(1);
		bot.getApi().sendMessage(message->chat->id, "......\n");
		sleep(1);
		bot.getApi().sendMessage(message->chat->id, "gets a kiss))");
		bot.getApi().sendMessage(my_chat, message->chat->firstName + " just recived: " + "kiss");

		f = fopen("userZ.txt", "a+");
		fprintf(f, "User %s wrote: %s\n", message->chat->firstName.c_str(), message->text.c_str());
		fclose(f);

		});*/

   /*bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
		if (StringTools::startsWith(message->text, "/start")) {
			return;
		}
		bot.getApi().sendMessage(message->chat->id, "Your message is: " + message->text);
		});*/

	try {
		printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
		TgBot::TgLongPoll longPoll(bot);
		static int flag = 2;
		while (flag) {
			bot.getEvents().onCommand("stop", [&bot](TgBot::Message::Ptr message) {
				if (message->chat->id != my_chat) {
					bot.getApi().sendMessage(message->chat->id, "Access denied!");
					return;
				}
				bot.getApi().sendMessage(my_chat, "bb suka)");
				std::cout << "bb\n";
				flag--;

				});
			printf("Long poll started\n");
			longPoll.start();

		}
	}
	catch (TgBot::TgException& e) {
		printf("error: %s\n", e.what());
	}

	return 0;
}
