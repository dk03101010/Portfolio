import glob
from bs4 import BeautifulSoup

for filename in glob.glob('*.html'):
    with open(filename, 'r') as f:
        page = f.read()
        soup = BeautifulSoup(page, 'html.parser')
        nameUni = soup.find('h1', class_='heading-title').get_text()
        name = nameUni.encode("utf-8")
        User_container = soup.find_all('div', class_='row page-row')
        category = soup.find_all('h3', class_='panel-title')
        research_info = soup.find_all('div', class_='panel-body')
        email = soup.find('img', class_='email-image', alt=True)
        webpage = soup.find_all('h3')
        for url in webpage:
            if url.find_all('a', href=True):
                weburl = url.find('a')['href']

    with open('text_file.txt', 'w', encoding='utf-8') as f_out:
        f_out.write('Name: ' + ' '.join(name.decode("ascii").split()))
        education = category[1].get_text()
        education = '\n' + education + ": " + research_info[1].get_text() + '\n'
        f_out.write(education)
        research = category[0].get_text()
        research = research + ": " + research_info[0].get_text() + '\n'
        f_out.write(research)
        f_out.write("Email: " + email['alt'])
        f_out.write("\nWebpage: " + weburl)
