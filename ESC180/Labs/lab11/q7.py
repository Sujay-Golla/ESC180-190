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


if __name__ == '__main__':
    proompt = "Write Python code to parse the CSV string that follows. Result needs to be a dictionary of dictionaries, and ONLY return the code WITH NO FORMATTING. Frequently, some values in a row of the table will be missing, so write out test cases to make sure that each type of value is properly recognized and added to the dictionary.  \n\n\n"
    s = """Date,Character,Age,HeightCm,AppleCount,MoodRating
            2025-01-15,Snow White,14,157.5,1,8.5
            Doc,200,91.4,3,7.2
            2025-01-16,Grumpy,199,89.0,0,3.4
            2025-01-16,202,94.0,2,9.7
            2025-01-17,Sleepy,202,90.2,1,6.3
            Bashful,198,88.5,1,5.8
            2025-01-18,Sneezy,197,92.3,2,7.4
            2025-01-18,Dopey,195,87.1,4,8.9
            2025-01-19,,42,175.6,0,2.1
            Prince,25,185.3,2,9.5
            2025-01-20,Huntsman,38,178.4,1,6.7
            2025-01-20,250,92.0,3,7.3
            2025-01-21,Forest Animals,5,30.5,4,9.2"""

    print("Q:", proompt)
    response = get_response(proompt)
    print("A:", response)

    print("----------------------------------")
    exec(response)

