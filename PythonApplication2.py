# -*- coding: utf-8 -*-
import smtplib
from email.message import EmailMessage
import sys
email_sender = 'yousef.rizk2023@gmail.com'
email_password = 'xyia stvf vlih yzke'
email_receiver = 'yousefrizk.2.2005@gmail.com'
if len(sys.argv) > 1:
    content = sys.argv[1]
else:
    content = "defaoult"

msg = EmailMessage()
msg['From'] = email_sender
msg['To'] = email_receiver
msg['Subject'] = 'send  C++'
msg.set_content(content)

try:
    with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
        smtp.login(email_sender, email_password)
        smtp.send_message(msg)
    print("EMAIL_SENT")
except Exception as e:
    print("EMAIL_FAILED", e)
