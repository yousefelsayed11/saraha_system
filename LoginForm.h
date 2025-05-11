#pragma once
#include"MessageForm.h"
#include"RegisterForm.h"

namespace team {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel1->Location = System::Drawing::Point(529, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(695, 681);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::panel1_Paint);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SeaGreen;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Text", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(96, 494);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(204, 51);
			this->button2->TabIndex = 29;
			this->button2->Text = L"Next";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &LoginForm::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SeaGreen;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Text", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(330, 494);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(204, 51);
			this->button1->TabIndex = 28;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::SeaGreen;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(147, 453);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(189, 17);
			this->checkBox1->TabIndex = 27;
			this->checkBox1->Text = L"I agree to the terms and conditions";
			this->checkBox1->UseVisualStyleBackColor = false;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &LoginForm::checkBox1_CheckedChanged);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::SeaGreen;
			this->panel5->Controls->Add(this->textBox2);
			this->panel5->Location = System::Drawing::Point(96, 372);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(329, 47);
			this->panel5->TabIndex = 26;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::SeaGreen;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(20, 16);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(227, 20);
			this->textBox2->TabIndex = 22;
			this->textBox2->Text = L"Password";
			this->textBox2->UseSystemPasswordChar = true;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &LoginForm::textBox2_TextChanged);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::SeaGreen;
			this->panel4->Controls->Add(this->textBox1);
			this->panel4->Location = System::Drawing::Point(96, 310);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(329, 46);
			this->panel4->TabIndex = 25;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::panel4_Paint);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::SeaGreen;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(20, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(227, 20);
			this->textBox1->TabIndex = 22;
			this->textBox1->Text = L"Email";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &LoginForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::SeaGreen;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Text", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(93, 250);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 43);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Login:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->panel2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel2.BackgroundImage")));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(533, 681);
			this->panel2->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Black;
			this->panel3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel3.BackgroundImage")));
			this->panel3->Location = System::Drawing::Point(137, 122);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(257, 246);
			this->panel3->TabIndex = 30;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::SeaGreen;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Text", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(146, 453);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(204, 57);
			this->button3->TabIndex = 29;
			this->button3->Text = L"Register";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &LoginForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::SeaGreen;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Text", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(198, 417);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"No Account\?";
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1224, 681);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LoginForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private:
			bool IsValidEmail(String^ email)
			{
				if (String::IsNullOrEmpty(email))
					return false;

				try
				{
					return email->Contains("@") &&
						email->IndexOf("@") > 0 &&
						email->LastIndexOf(".") > email->IndexOf("@") + 1;

				}
				catch (Exception^)
				{
					return false;

				}

			}

			bool IsValidPassword(String^ password)
			{
				// Password must be at least 8 characters and contain letters and numbers
				if (password->Length < 8)
					return false;

				bool hasLetter = false;
				bool hasDigit = false;
				for each (Char c in password)
				{
					if (Char::IsLetter(c)) hasLetter = true;
					if (Char::IsDigit(c)) hasDigit = true;
				}

				return hasLetter && hasDigit;
			}


	private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox1->Checked)
	{
		button1->Enabled = true;
	}
	else
	{
		button1->Enabled = false;
	}
}


private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "Email(username@gamil.com)")
	{
		textBox1->Text = "";
	}
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox2->Text == "Password")
	{
		textBox2->Text = "";
	}
}



private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ email = textBox1->Text->Trim();
	String^ password = textBox2->Text->Trim();

	
	if (String::IsNullOrWhiteSpace(email))
	{
		MessageBox::Show("Please enter your email address", "Input Error",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
		textBox1->Focus();
		return;
	}

	if (String::IsNullOrWhiteSpace(password))
	{
		MessageBox::Show("Please enter your password", "Input Error",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
		textBox2->Focus();
		return;
	}

	
	if (!email->Contains("@") || email->IndexOf("@") == 0 ||
		!email->Contains(".") || email->LastIndexOf(".") < email->IndexOf("@"))
	{
		MessageBox::Show("Please enter a valid email address", "Invalid Email",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
		textBox1->Focus();
		textBox1->SelectAll();
		return;
	}
	
	if (password->Length < 8)
	{
		MessageBox::Show("Password must be at least 8 characters long",
			"Invalid Password", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		textBox2->Focus();
		textBox2->SelectAll();
		return;
	}

	if (!ContainsLettersAndNumbers(password))
	{
		MessageBox::Show("Password must contain both letters and numbers",
			"Invalid Password", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		textBox2->Focus();
		textBox2->SelectAll();
		return;
	}

	
	if (email->Equals("zeinab@gmail.com", StringComparison::OrdinalIgnoreCase) &&
		password == "zeinab123")
	{
		MessageBox::Show("Sign in successful!", "Success",
			MessageBoxButtons::OK, MessageBoxIcon::Information);

		// move to FirstForm
		//StartForm^ startform = gcnew StartForm();
		//startform->Show();
		//this->Hide();
	}
	else
	{
		MessageBox::Show("The email or password you entered is incorrect",
			"Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
		textBox2->Focus();
		textBox2->SelectAll();
	}
}


	   bool ContainsLettersAndNumbers(String^ str)
	   {
		   bool hasLetter = false;
		   bool hasDigit = false;

		   for each (Char c in str)
		   {
			   if (Char::IsLetter(c)) hasLetter = true;
			   if (Char::IsDigit(c)) hasDigit = true;
		   }

		   return hasDigit && hasLetter;
	   }

	   //حل مؤقت ولما نعمل الفايلات هيتمسح وهيدخل علي الصفحة الرئيسية علي طول لما يعمل submit
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageForm^ messageform = gcnew MessageForm();
	messageform->Show();
	this->Hide();
}



private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	RegisterForm^ registerform = gcnew RegisterForm();
	registerform->Show();
	this->Hide();
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
