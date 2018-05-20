from bs4 import BeautifulSoup
import requests
import os
from zipfile import *
import logging

abs_path = os.path.abspath(os.path.curdir)
log_file_name = os.path.join(abs_path, "logfile.log")
log_format = "%(asctime)s -     %(message)s"
logging.basicConfig(filename=log_file_name,level=logging.DEBUG, format=log_format,filemode="w")
logger = logging.getLogger()
html = requests.get('https://download.quranicaudio.com/quran/').text
soup = BeautifulSoup(html, 'lxml')
logger.info("Total Qari: 32")
#print(soup.prettify())
total_qaris = 0
name_links = soup.find('pre')
for name in name_links.find_all('a'):
    if name.text[0].isalpha():
        name = name.text.replace("/", "")
        logger.info("Processing: "+str(total_qaris)+" out of 32")
        logger.info("Qari Name: " + str(name))
        if not os.path.exists(name):
            os.makedirs(name)
            os.chdir(os.path.curdir+'/'+name)
            mp3_files = requests.get('https://download.quranicaudio.com/quran/' + name + '/').text
            soup2 = BeautifulSoup(mp3_files, 'lxml')
            file_links = soup2.find('pre')
            file = file_links.find_all('a')
            total_files = len(file) - 1
            critical_value = total_files - 2
            count = 0
            zip_archive = ZipFile("mp3files.zip", "w")
            for f in file:
                if count >= critical_value:
                    file_name = f.text.replace("/","")

                    try:
                        logger.debug("Downloading file: " + str(file_name) + "for " + name)
                        res = requests.get('https://download.quranicaudio.com/quran/' + name + '/'+file_name,stream = True)
                        f = open(file_name, "wb+")
                        for chunk in res.iter_content(chunk_size=1024*1024):
                            if(chunk):
                                f.write(chunk)
                        logger.debug("Done downloading file : "+ str(file_name) + "for" + name)
                        zip_archive.write(file_name)
                        #os.remove(file_name)
                        f.close()
                    except Exception as e:
                        logger.error("Some exception occured")
                        print(e)
                        print("Some exception occured file could not be downloaded: "+ str(count))
                count += 1
            logger.debug("merging all files")
            all_files = os.listdir(os.path.abspath(os.path.curdir))
            for a_file in all_files:
                if a_file.endswith(".mp3"):
                    os.remove(os.path.join(os.path.abspath(os.path.curdir),a_file))
            logger.debug("merging complete for qari: " + str(name))
            os.chdir(abs_path)
            zip_archive.close()
    total_qaris += 1