import asyncio
import telegram

async def main():
    bot = telegram.Bot("7496912013:AAE57gIZmfNgjAxVCKa1kXAUoy1jWimbQlE")
    async with bot:
        print(await bot.get_me())

if __name__ == '__main__':
    asyncio.run(main())
