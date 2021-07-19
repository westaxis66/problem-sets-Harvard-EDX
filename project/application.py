import os
import re
import smtplib, ssl
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_mail import Mail, Message
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash
from decouple import config
from dotenv import load_dotenv
load_dotenv()





# Configure application
app = Flask(__name__)
app.secret_key = b'_5#y2L"F4Q8z\n\xec]/'


app.config["MAIL_DEFAULT_SENDER"] = os.getenv("MAIL_DEFAULT_SENDER")
app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
app.config["MAIL_PORT"] = 587
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
mail = Mail(app)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

db = SQL("sqlite:///finalproject.db")



@app.route("/", methods=["GET","POST"])
def finalproject():
    if request.method == "POST":

        name = request.form.get("name")
        if not name:
            return render_template("error.html", message="Missing Name")

        email = request.form.get("email")
        if not email:
            return render_template("error.html", message="Missing E-mail")




        db.execute("INSERT INTO register_2 (name, email) VALUES(?, ?)", name, email)





        message = Message("You are registered!", recipients=[email])

        mail.send(message)

        flash("You are registered", "info")



        return redirect("/")







    else:
        return render_template("finalproject.html")








@app.route("/contact", methods=["GET", "POST"])
def contact():
    return render_template("contact.html")



@app.route("/examples", methods=["GET", "POST"])
def examples():
    return render_template("examples.html")




@app.route("/otherstuff", methods=["GET", "POST"])
def otherstuff():
    return render_template("otherstuff.html")






