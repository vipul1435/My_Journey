# here we are using pytube module for the project
from ast import Delete
from pytube import YouTube
link = input("Enter the link of Youtube video")
youtube = YouTube(link)
print(youtube.title)
print(youtube.thumbnail_url)
cleaity = youtube.streams.all()
vid = list(enumerate(cleaity))
print("Press 1 for 1080")
print("Press 2 for 720")
print("Press 3 for 360")
print("Press 4 for 144")
dics = {
    1:1080,
    2:720,
    3:360,
    4:144
}
received = -1
user  = int(input())
for i in vid:
    if(int(i.resolution)==dics[user]):
        received= i
        break
if(received!=-1):
    cleaity[received].download()
    print("Succesfully donloaded")
else:
    print("Not Avilable")
