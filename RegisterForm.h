namespace team {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
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
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^ radioButton2;
	protected:
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::SeaGreen;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(701, 482);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(78, 25);
			this->radioButton2->TabIndex = 16;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Female";
			this->radioButton2->UseVisualStyleBackColor = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::SeaGreen;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(594, 482);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(62, 25);
			this->radioButton1->TabIndex = 15;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Male";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &RegisterForm::radioButton1_CheckedChanged);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::SeaGreen;
			this->panel4->Controls->Add(this->textBox3);
			this->panel4->Location = System::Drawing::Point(566, 365);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(355, 46);
			this->panel4->TabIndex = 13;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::SeaGreen;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(12, 13);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(201, 20);
			this->textBox3->TabIndex = 2;
			this->textBox3->Text = L"Password";
			this->textBox3->UseSystemPasswordChar = true;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &RegisterForm::textBox3_TextChanged);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::SeaGreen;
			this->panel5->Controls->Add(this->textBox4);
			this->panel5->Location = System::Drawing::Point(566, 430);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(355, 46);
			this->panel5->TabIndex = 14;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::SeaGreen;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(12, 13);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(201, 20);
			this->textBox4->TabIndex = 2;
			this->textBox4->Text = L"Confirm Password";
			this->textBox4->UseSystemPasswordChar = true;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &RegisterForm::textBox4_TextChanged);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::SeaGreen;
			this->panel3->Controls->Add(this->textBox2);
			this->panel3->Location = System::Drawing::Point(566, 300);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(355, 46);
			this->panel3->TabIndex = 12;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::SeaGreen;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(13, 12);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(201, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Text = L"Email";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &RegisterForm::textBox2_TextChanged);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::SeaGreen;
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Location = System::Drawing::Point(566, 231);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(355, 46);
			this->panel2->TabIndex = 11;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::SeaGreen;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Display", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(202, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Full Name";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &RegisterForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::SeaGreen;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Text", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(570, 173);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(256, 43);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Create Account:";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SeaGreen;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Text", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(760, 545);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 54);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &RegisterForm::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Location = System::Drawing::Point(162, 173);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(179, 176);
			this->panel1->TabIndex = 21;
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1224, 681);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label2);
			this->DoubleBuffered = true;
			this->Name = L"RegisterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RegisterForm";
			this->Load += gcnew System::EventHandler(this, &RegisterForm::RegisterForm_Load);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

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
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "Full Name")
		{
			textBox1->Text = "";
		}

	}

private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox2->Text == "Email (username@gmail.com)")
	{
		textBox2->Text = "";
	}
}

private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox3->Text == "Password")
	{
		textBox2->Text = "";
	}
}

private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textBox4->Text == " confirm Password")
	{
		textBox4->Text = "";
	}
}

	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ selectgender;
		if (radioButton1->Checked) {
			selectgender = "Male";

		}
		else if (radioButton2->Checked) {
			selectgender = "Female";
		}
		else {

			MessageBox::Show("please select your gender!", "error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		MessageBox::Show("select gender:" + selectgender, "success");
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ name = textBox1->Text;
	String^ email = textBox2->Text;
	String^ password = textBox3->Text;
	String^ confirmPassword = textBox4->Text;
	String^ gender = radioButton1->Checked ? "Male" : (radioButton2->Checked ? "Female" : "");

	
	if (name == "" || name == "Enter your Full name")
	{
		MessageBox::Show("Please Enter Full Name", "Invaild", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (email == "" || email == "Enter your Email")
	{
		MessageBox::Show("Please Enter Email", "Invaild", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (!IsValidEmail(email))
	{
		MessageBox::Show("Invaild Email Format", "incorrect", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (password == "" || password == "Password")
	{
		MessageBox::Show("Enter your Password", "invaild", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (!IsValidPassword(password))
	{
		MessageBox::Show("Password must contain at least 8 characters including numbers, letters", "invaild", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (password != confirmPassword) {

		MessageBox::Show("passwords don’n match", "invaild", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;

	}


	if (gender == "")
	{
		MessageBox::Show("please select gender", "incorrect", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}




	MessageBox::Show("Registration Successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	
		// move to FirstForm
		MessageForm^ messageform = gcnew MessageForm();
		messageform->Show();
		this->Hide();

}


private: System::Void RegisterForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
