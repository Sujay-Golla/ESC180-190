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

def check_result(response, test_cases):
    exec(response, globals())
    for key, value in test_cases.items():
        if factorial(key) != value:
            return False
    return True

if __name__ == '__main__':
    proompt = "Write a Python function that takes an argument n and returns the factorial of n\n ONLY RETURN THE CODE without any formatting"
    print("Q:", proompt)
    response = get_response(proompt)
    print("A:", response)
    test_cases = {3:6, 1:1, 5:120}
    print(check_result(response, test_cases))