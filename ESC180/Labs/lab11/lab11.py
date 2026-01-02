from notopenai import NotOpenAI
import json

API_KEY = "iM1qQy9qGbcHVjj7NLDJ"
CLIENT = NotOpenAI(api_key=API_KEY)

def get_response(prompt):
    chat_completion = CLIENT.chat.completions.create(
    messages=[
        {
        "role": "user",
        "content": prompt,
        }
    ],
    model="gpt-3.5-turbo", # the GPT model to use
    )
    response_str = chat_completion.choices[0].message.content
    return response_str

proompt = "Q: What is the meaning of life?"
proompt += "\nA: " + get_response(proompt)
print(proompt)
inp = input("Next Question: ")
while inp != "STOP":
    proompt += "Q: " + inp
    proompt += "A: " + get_response(proompt)
    print(proompt)
    inp = input("Next Question: ")
