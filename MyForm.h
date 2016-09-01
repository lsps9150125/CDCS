#pragma once
#include <windows.h>
#include<iostream>
#include<fstream>
#include "cppjieba/Jieba.hpp"
#include "cppjieba/KeywordExtractor.hpp"

const char* const DICT_PATH = "dict/jieba.dict.utf8";
const char* const HMM_PATH = "dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "dict/user.dict.utf8";
const char* const IDF_PATH = "dict/idf.utf8";
const char* const STOP_WORD_PATH = "dict/stop_words.utf8";

namespace CDCS {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	public:


	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  filedirct_textbox;
	protected:
	private: System::Windows::Forms::Button^  filedirct_button;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  informationBox1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::GroupBox^  File_groupBox;
	private: System::Windows::Forms::GroupBox^  Jeiba_groupBox;



	private: System::Windows::Forms::RadioButton^  MultipleSelect_RadioButton;

	private: System::Windows::Forms::RadioButton^  SingleSelect_RadionButton;
	private: System::Windows::Forms::RadioButton^  AllSelect_RadioButton;
	private: System::Windows::Forms::Button^  Jeiba_button;









	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->filedirct_textbox = (gcnew System::Windows::Forms::TextBox());
			this->filedirct_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->informationBox1 = (gcnew System::Windows::Forms::TextBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->File_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->Jeiba_groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->Jeiba_button = (gcnew System::Windows::Forms::Button());
			this->AllSelect_RadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->MultipleSelect_RadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->SingleSelect_RadionButton = (gcnew System::Windows::Forms::RadioButton());
			this->File_groupBox->SuspendLayout();
			this->Jeiba_groupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// filedirct_textbox
			// 
			this->filedirct_textbox->Location = System::Drawing::Point(94, 21);
			this->filedirct_textbox->Name = L"filedirct_textbox";
			this->filedirct_textbox->ReadOnly = true;
			this->filedirct_textbox->Size = System::Drawing::Size(233, 22);
			this->filedirct_textbox->TabIndex = 0;
			// 
			// filedirct_button
			// 
			this->filedirct_button->Location = System::Drawing::Point(333, 21);
			this->filedirct_button->Name = L"filedirct_button";
			this->filedirct_button->Size = System::Drawing::Size(63, 23);
			this->filedirct_button->TabIndex = 1;
			this->filedirct_button->Text = L"預覽";
			this->filedirct_button->UseVisualStyleBackColor = true;
			this->filedirct_button->Click += gcnew System::EventHandler(this, &MyForm::filedirct_button_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(6, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"資料夾位置";
			// 
			// informationBox1
			// 
			this->informationBox1->Location = System::Drawing::Point(422, 290);
			this->informationBox1->Multiline = true;
			this->informationBox1->Name = L"informationBox1";
			this->informationBox1->ReadOnly = true;
			this->informationBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->informationBox1->Size = System::Drawing::Size(510, 380);
			this->informationBox1->TabIndex = 3;
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 15;
			this->listBox1->Location = System::Drawing::Point(422, 13);
			this->listBox1->Name = L"listBox1";
			this->listBox1->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listBox1->Size = System::Drawing::Size(510, 259);
			this->listBox1->TabIndex = 4;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// File_groupBox
			// 
			this->File_groupBox->Controls->Add(this->filedirct_textbox);
			this->File_groupBox->Controls->Add(this->filedirct_button);
			this->File_groupBox->Controls->Add(this->label1);
			this->File_groupBox->Location = System::Drawing::Point(14, 12);
			this->File_groupBox->Name = L"File_groupBox";
			this->File_groupBox->Size = System::Drawing::Size(402, 62);
			this->File_groupBox->TabIndex = 5;
			this->File_groupBox->TabStop = false;
			this->File_groupBox->Text = L"資料夾位置";
			// 
			// Jeiba_groupBox
			// 
			this->Jeiba_groupBox->Controls->Add(this->Jeiba_button);
			this->Jeiba_groupBox->Controls->Add(this->AllSelect_RadioButton);
			this->Jeiba_groupBox->Controls->Add(this->MultipleSelect_RadioButton);
			this->Jeiba_groupBox->Controls->Add(this->SingleSelect_RadionButton);
			this->Jeiba_groupBox->Location = System::Drawing::Point(14, 80);
			this->Jeiba_groupBox->Name = L"Jeiba_groupBox";
			this->Jeiba_groupBox->Size = System::Drawing::Size(402, 157);
			this->Jeiba_groupBox->TabIndex = 6;
			this->Jeiba_groupBox->TabStop = false;
			this->Jeiba_groupBox->Text = L"中文分詞";
			// 
			// Jeiba_button
			// 
			this->Jeiba_button->Location = System::Drawing::Point(333, 22);
			this->Jeiba_button->Name = L"Jeiba_button";
			this->Jeiba_button->Size = System::Drawing::Size(63, 23);
			this->Jeiba_button->TabIndex = 3;
			this->Jeiba_button->Text = L"分詞";
			this->Jeiba_button->UseVisualStyleBackColor = true;
			this->Jeiba_button->Click += gcnew System::EventHandler(this, &MyForm::Jeiba_button_Click);
			// 
			// AllSelect_RadioButton
			// 
			this->AllSelect_RadioButton->AutoSize = true;
			this->AllSelect_RadioButton->Location = System::Drawing::Point(7, 68);
			this->AllSelect_RadioButton->Name = L"AllSelect_RadioButton";
			this->AllSelect_RadioButton->Size = System::Drawing::Size(37, 16);
			this->AllSelect_RadioButton->TabIndex = 2;
			this->AllSelect_RadioButton->Text = L"All";
			this->AllSelect_RadioButton->UseVisualStyleBackColor = true;
			this->AllSelect_RadioButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::AllSelect_RadioButton_CheckedChanged);
			// 
			// MultipleSelect_RadioButton
			// 
			this->MultipleSelect_RadioButton->AutoSize = true;
			this->MultipleSelect_RadioButton->Location = System::Drawing::Point(9, 45);
			this->MultipleSelect_RadioButton->Name = L"MultipleSelect_RadioButton";
			this->MultipleSelect_RadioButton->Size = System::Drawing::Size(62, 16);
			this->MultipleSelect_RadioButton->TabIndex = 1;
			this->MultipleSelect_RadioButton->Text = L"Multiple";
			this->MultipleSelect_RadioButton->UseVisualStyleBackColor = true;
			this->MultipleSelect_RadioButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::MultipleSelect_RadioButton_CheckedChanged);
			// 
			// SingleSelect_RadionButton
			// 
			this->SingleSelect_RadionButton->AutoSize = true;
			this->SingleSelect_RadionButton->Checked = true;
			this->SingleSelect_RadionButton->Location = System::Drawing::Point(9, 22);
			this->SingleSelect_RadionButton->Name = L"SingleSelect_RadionButton";
			this->SingleSelect_RadionButton->Size = System::Drawing::Size(52, 16);
			this->SingleSelect_RadionButton->TabIndex = 0;
			this->SingleSelect_RadionButton->TabStop = true;
			this->SingleSelect_RadionButton->Text = L"Single";
			this->SingleSelect_RadionButton->UseVisualStyleBackColor = true;
			this->SingleSelect_RadionButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::SingleSelect_RadionButton_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(944, 682);
			this->Controls->Add(this->Jeiba_groupBox);
			this->Controls->Add(this->File_groupBox);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->informationBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->File_groupBox->ResumeLayout(false);
			this->File_groupBox->PerformLayout();
			this->Jeiba_groupBox->ResumeLayout(false);
			this->Jeiba_groupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void filedirct_button_Click(System::Object^  sender, System::EventArgs^  e) {
		folderBrowserDialog1->ShowDialog();
		System::String ^dir = folderBrowserDialog1->SelectedPath;
		filedirct_textbox->Text = dir;
		listBox1->Items->Clear();
		listBox1->Items->AddRange(IO::Directory::GetFiles(dir,"*.txt"));
		listBox1->SelectionMode = SelectionMode::One;
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (listBox1->SelectedIndex != -1) {
			StreamReader ^ sr = gcnew StreamReader(listBox1->Items[listBox1->SelectedIndex]->ToString(), System::Text::Encoding::Default);
			informationBox1->Text = sr->ReadToEnd();
			sr->Close();
		}
	}	
	private: System::Void SingleSelect_RadionButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {		
		listBox1->ClearSelected();
		listBox1->SelectionMode = SelectionMode::One;
	}
	private: System::Void MultipleSelect_RadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {		
		listBox1->ClearSelected();
		listBox1->SelectionMode = SelectionMode::MultiSimple;
	}
	private: System::Void AllSelect_RadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {		
		listBox1->ClearSelected();
		listBox1->SelectionMode = SelectionMode::MultiSimple;
		for (int i = 0; i < listBox1->Items->Count; i++)
		{
			listBox1->SetSelected(i, true);
		}
	}
	private: System::Void Jeiba_button_Click(System::Object^  sender, System::EventArgs^  e) {
		if (SingleSelect_RadionButton->Checked == TRUE) {
			System::String^ InputS = informationBox1->Text;
			const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(InputS)).ToPointer();
			string dest = chars;
			cppjieba::Jieba jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH);
			vector<string> words;
			vector<cppjieba::Word> jiebawords;
			jieba.Cut(dest, words, true);
			string str = limonp::Join(words.begin(), words.end(), "/");
			informationBox1->Text = gcnew String(str.c_str());
		}
		else if(MultipleSelect_RadioButton->Checked == TRUE) {
			informationBox1->Text = "1";
		}
		else if (AllSelect_RadioButton->Checked == TRUE) {
			informationBox1->Text = "1";
		}
		else {
			MessageBox::Show("請選要要分詞文件數量");
		}
			
	}
};
}
