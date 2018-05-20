import os
from bs4 import BeautifulSoup
import requests

keywords = []
ask = "Y"
while ask == "Y" or ask == "y":
    word = input("Enter word:")
    keywords.append(word)
    ask = input("Do you want to enter another word: (Y/N)")

url_list = []
flag = False
html = requests.get('https://propakistani.pk/').text
soup = BeautifulSoup(html, 'lxml')
page_count = 0

for article in soup.find_all('article'):
    if page_count == 6:
        break
    page_count += 1
    news_link = article.find('a')['href']
    #print(news_link)
    html2 = requests.get(news_link).text
    soup2 = BeautifulSoup(html2, 'lxml')
    article2 = soup2.find('article')
    for h1_tag in article2.find_all('h1'):
        #print(h1_tag.text)
        for word in keywords:
            #print("word: " + word)
            if (word.lower() in h1_tag.text) or (word.title() in h1_tag.text):
                flag = True
                break
        else:
            continue
        break
    if flag == False:
        for h2_tag in article2.find_all('h2'):
            #print(h4_tag.text)
            for word in keywords:
                if (word.lower() in h2_tag.text) or (word.title() in h2_tag.text):
                    flag = True
                    break
            else:
                continue
            break
    if flag == False:
        for h3_tag in article2.find_all('h3'):
            #print(h4_tag.text)
            for word in keywords:
                if (word.lower() in h3_tag.text) or (word.title() in h3_tag.text):
                    flag = True
                    break
            else:
                continue
            break
    if flag == False:
        for h4_tag in article2.find_all('h4'):
            #print(h4_tag.text)
            for word in keywords:
                if (word.lower() in h4_tag.text) or (word.title() in h4_tag.text):
                    flag = True
                    break
            else:
                continue
            break
    if flag == False:
        for h5_tag in article2.find_all('h5'):
            #print(h4_tag.text)
            for word in keywords:
                if (word.lower() in h5_tag.text) or (word.title() in h5_tag.text):
                    flag = True
                    break
            else:
                continue
            break
    if flag == False:
        for para in article2.find_all('p'):
            #print(para.text)
            for word in keywords:
                if (word.lower() in para.text) or (word.title() in para.text):
                    flag = True
                    break
            else:
                continue
            break
    if flag == False:
        for ul in article2.find_all('ul'):
            for li in ul.find_all('li'):
                for word in keywords:
                    if word in li.text:
                        flag = True
                        break
                else:
                    continue
                break
            else:
                continue
            break
    if flag == False:
        for quote_tag in article2.find_all('blockquote'):
            for para2 in quote_tag.find_all('p'):
                for word in keywords:
                    if word in para2.text:
                        flag = True
                        break
                else:
                    continue
                break
            else:
                continue
            break

    if flag == True:
        url_list.append(news_link)
        flag = False

print(url_list)