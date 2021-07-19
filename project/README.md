# BBT Web design and Development
### my video<URL> https://youtu.be/PzxHv7gUUPo
### Description of project: Wed site for Web Design and Devlopment company.

###  This project is a web page for a future web design and development company named BBT Web Design and Development.
### This site uses HTML, CSS, Flask, SQL, JavaScript and Python. The project has several files.
### A templet file, a static file and a node file. In the templet file are several pages, all interlinked,
### as well as an application page written in Flask/Python and a database written in SQL.
### Also, an environmental file for the email formation. In the static file there is a CSS page named finalprojectcss.css.
### The purpose of this web page is to give potential customers information and direction of the company as well as some
### examples of past work and options they can browse through to gain an idea of what types of services
### are available and what their potential coast might be.

###  In the Templet folder under finalproject.html the page starts with two href tags in the head.
### One to import bootstrap and the other the CSS folder. Below the hrefs are two meta tags to allow for mobile device viewing.
### In the Body there is a h1 header that fades from blue to black with a shadow. Below the header I have two div’s that take
### the form of two boxes side by side. One with the h2 heading “Mission Statement” of which will be the general function and
### purpose of the site the other is a space for general marketing elements like sales and promotions.

###  Under the display boxes there is a registration button with a small statement urging potential customers to register with our company.
### Upon the “onlclick” the “Register” button will open a registration form inside a popup. The popup is written in HTML and CSS
### and the buttons activate a JavaScript function that opens and closes Customers are asked to give their name and email and then
### to press submit. Once submitted the name and email are registered in a database named finalproject.db.

###  After the name and email are entered into the database using a SQL command an automatic email is sent to the new registrant
### from the application page using Flask/Python. At the time of the automatically generated email is sent a “flash” command
### is generated with the message that the customer is now registered under the register button.
### At the bottom of the page is a footer and a nav tag that takes users to the other three pages of the site.
### There are three hrefs in list format in the nav bar. One taking the user to the Contacts page, the Examples page and finally the About US page.

###  The Finalproject.html page is used as a layout page for the other pages. The first being the Contact page of which is outfitted with
### a place for phone number, email and social media links. These are set up in a list format with anchor tags and hrefs to Facebook, Twitter,
### YouTube and Instagram.  In the div box next to it is a space for a list of services set in a list format for easy viewing.
### Finally, at the bottom of the page is the same footer adjusted for the other three pages.

###  The next page is the Examples page in the same layout with one box containing images of previous work.
### These are arranged next to each other in an appropriate size to fit the div box. They are imaged tagged with the source tag
### referencing images downloaded into the static file. The div next to it is dedicated to images of template pages that
### will be available for the customers. These are set up in the same configuration side by side and to fit the div box with
### an image tag sourced from a download in the static file. At the end of the page is the footer adjusted for the appropriate hrefs.

###  The Final page is titled “otherstuff” however, it is the “About Us page. Set in the same layout with a div box designated for a summary
### of the team and our business background, the other dedicated to pricing variation. Ending the page with a footer with appropriately adjusted hrefs.
### In the application.py page a secret key is established and a flask code setting up an email sender with .env file and a mail app.
### An app that configures auto reload and the importation of the database. Next is the finalproject function of which handles the popup form
### and the insertion of the data into the data base as well as an automatically generated email followed by a flash function generated
### at the completion of the auto email. Finally, being redirect to the index page.
























In the Templet folder under finalproject.html the page starts with two href tags in the head. One to import bootstrap and the other the CSS folder. Below the hrefs are two meta tags to allow for mobile device viewing. In the Body there is a h1 header that fades from blue to black with a shadow. Below the header I have two div’s that take the form of two boxes side by side. One with the h2 heading “Mission Statement” of which will be the general function and purpose of the site the other is a space for general marketing elements like sales and promotions.
  Under the display boxes there is a registration button with a small statement urging potential customers to register with our company. Upon the “onlclick” the “Register” button will open a registration form inside a popup. The popup is written in HTML and CSS and the buttons activate a JavaScript function that opens and closes the form. Customers are asked to give their name and email and then to press submit. Once submitted the name and email are registered in a database named finalproject.db.
  After the name and email are entered into the database using a SQL command an automatic email is sent to the new registrant from the application page using Flask/Python. At the time of the automatically generated email is sent a “flash” command is generated with the message that the customer is now registered under the register button.
  At the bottom of the page is a footer and a nav tag that takes users to the other three pages of the site. There are three hrefs in list format in the nav bar. One taking the user to the Contacts page, the Examples page and finally the About US page.
  The Finalproject.html page is used as a layout page for the other pages. The first being the Contact page of which is outfitted with a place for phone number, email and social media links. These are set up in a list format with anchor tags and hrefs to Facebook, Twitter, YouTube and Instagram.  In the div box next to it is a space for a list of services set in a list format for easy viewing. Finally, at the bottom of the page is the same footer adjusted for the other three pages.
  The next page is the Examples page in the same layout with one box containing images of previous work. These are arranged next to each other in an appropriate size to fit the div box. They are imaged tagged with the source tag referencing images downloaded into the static file. The div next to it is dedicated to images of template pages that will be available for the customers. These are set up in the same configuration side by side and to fit the div box with an image tag sourced from a download in the static file. At the end of the page is the footer adjusted for the appropriate hrefs.
  The Final page is titled “otherstuff” however, it is the “About Us page. Set in the same layout with a div box designated for a summary of the team and our business background, the other dedicated to pricing variation. Ending the page with a footer with appropriately adjusted hrefs.
  In the application.py page a secret key is established and a flask code setting up an email sender with .env file and a mail app. An app that configures auto reload and the importation of the database. Next is the finalproject function of which handles the popup form and the insertion of the data into the data base as well as an automatically generated email followed by a flash function generated at the completion of the auto email. Finally, being redirect to the index page.

