#pragma once

namespace RestaurantView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Model
	/// </summary>
	public ref class Model : public System::Windows::Forms::Form {

	public:
		Model(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		String^ conStr = InitializeConnection();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Model()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::CheckBox^ showEmployees;
	private: System::Windows::Forms::Button^ eraddrSearch;
	private: System::Windows::Forms::TextBox^ eraddrTextBox;
	private: System::Windows::Forms::Label^ eraddrLabel;
	private: System::Windows::Forms::Button^ ernameSearch;
	private: System::Windows::Forms::TextBox^ ernameTextBox;
	private: System::Windows::Forms::Label^ ernameLabel;
	private: System::Windows::Forms::Button^ eridSearch;
	private: System::Windows::Forms::TextBox^ eridTextBox;
	private: System::Windows::Forms::Button^ rmShowAll;
	private: System::Windows::Forms::GroupBox^ stockStatusBox;
	private: System::Windows::Forms::CheckBox^ noStockCh;
	private: System::Windows::Forms::CheckBox^ loStockCh;
	private: System::Windows::Forms::CheckBox^ inStockCh;
	private: System::Windows::Forms::GroupBox^ itemTypeBox;
	private: System::Windows::Forms::CheckBox^ rmiDrinkCh;
	private: System::Windows::Forms::CheckBox^ rmiFoodCh;
	private: System::Windows::Forms::Button^ rmSearch;
	private: System::Windows::Forms::Button^ rmicountSearch;
	private: System::Windows::Forms::TextBox^ rmicountTextBox;
	private: System::Windows::Forms::Label^ rmicountLabel;
	private: System::Windows::Forms::Button^ rminameSearch;
	private: System::Windows::Forms::TextBox^ rminameTextBox;
	private: System::Windows::Forms::Label^ rminameLabel;
	private: System::Windows::Forms::Button^ rmnameSearch;
	private: System::Windows::Forms::Button^ rmidSearch;
	private: System::Windows::Forms::TextBox^ rmnameTextBox;
	private: System::Windows::Forms::Label^ rmnameLabel;
	private: System::Windows::Forms::TextBox^ rmidTextBox;
	private: System::Windows::Forms::Label^ rmidLabel;
	private: System::Windows::Forms::Button^ rmstatusSearch;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ eridLabel;
	private: System::Windows::Forms::BindingSource^ bindingSRC;
	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::TabPage^ empTab;
	private: System::Windows::Forms::TabPage^ restTab;
	private: System::Windows::Forms::TabControl^ modelTab;
	private: System::Windows::Forms::TabPage^ menuTab;
	private: System::Windows::Forms::Button^ rcountSearch;
	private: System::Windows::Forms::Button^ rlocationSearch;
	private: System::Windows::Forms::Button^ rnameSearch;
	private: System::Windows::Forms::Button^ ridSearch;
	private: System::Windows::Forms::TextBox^ rcountTextBox;
	private: System::Windows::Forms::Label^ rcountLabel;
	private: System::Windows::Forms::TextBox^ rlocationTextBox;
	private: System::Windows::Forms::Label^ rlocationLabel;
	private: System::Windows::Forms::TextBox^ rnameTextBox;
	private: System::Windows::Forms::Label^ rnameLabel;
	private: System::Windows::Forms::TextBox^ ridTextBox;
	private: System::Windows::Forms::Label^ ridLabel;
	private: System::Windows::Forms::Button^ rShowAll;
	private: System::Windows::Forms::Button^ rSearch;
	private: System::Windows::Forms::Button^ ppaySearch;
	private: System::Windows::Forms::TextBox^ ppayTextBox;
	private: System::Windows::Forms::Label^ ppayLabel;
	private: System::Windows::Forms::Button^ pnameSearch;
	private: System::Windows::Forms::TextBox^ pnameTextBox;
	private: System::Windows::Forms::Label^ pnameLabel;
	private: System::Windows::Forms::Button^ pidSearch;
	private: System::Windows::Forms::TextBox^ pidTextBox;
	private: System::Windows::Forms::Label^ pidLabel;
	private: System::Windows::Forms::Button^ eaddressSearch;
	private: System::Windows::Forms::TextBox^ eaddressTextBox;
	private: System::Windows::Forms::Label^ eaddressLabel;
	private: System::Windows::Forms::Button^ enameSearch;
	private: System::Windows::Forms::TextBox^ enameTextBox;
	private: System::Windows::Forms::Label^ enameLabel;
	private: System::Windows::Forms::Button^ eidSearch;
	private: System::Windows::Forms::TextBox^ eidTextBox;
	private: System::Windows::Forms::Label^ eidLabel;
	private: System::Windows::Forms::Button^ epShowAll;
	private: System::Windows::Forms::Button^ pSearch;
	private: System::Windows::Forms::Button^ eSearch;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Model::typeid));
			this->bindingSRC = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->empTab = (gcnew System::Windows::Forms::TabPage());
			this->epShowAll = (gcnew System::Windows::Forms::Button());
			this->pSearch = (gcnew System::Windows::Forms::Button());
			this->ppaySearch = (gcnew System::Windows::Forms::Button());
			this->ppayTextBox = (gcnew System::Windows::Forms::TextBox());
			this->eSearch = (gcnew System::Windows::Forms::Button());
			this->ppayLabel = (gcnew System::Windows::Forms::Label());
			this->pnameSearch = (gcnew System::Windows::Forms::Button());
			this->pnameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->pnameLabel = (gcnew System::Windows::Forms::Label());
			this->pidSearch = (gcnew System::Windows::Forms::Button());
			this->pidTextBox = (gcnew System::Windows::Forms::TextBox());
			this->pidLabel = (gcnew System::Windows::Forms::Label());
			this->eaddressSearch = (gcnew System::Windows::Forms::Button());
			this->eaddressTextBox = (gcnew System::Windows::Forms::TextBox());
			this->eaddressLabel = (gcnew System::Windows::Forms::Label());
			this->enameSearch = (gcnew System::Windows::Forms::Button());
			this->enameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->enameLabel = (gcnew System::Windows::Forms::Label());
			this->eidSearch = (gcnew System::Windows::Forms::Button());
			this->eidTextBox = (gcnew System::Windows::Forms::TextBox());
			this->eidLabel = (gcnew System::Windows::Forms::Label());
			this->restTab = (gcnew System::Windows::Forms::TabPage());
			this->eraddrSearch = (gcnew System::Windows::Forms::Button());
			this->eraddrTextBox = (gcnew System::Windows::Forms::TextBox());
			this->eraddrLabel = (gcnew System::Windows::Forms::Label());
			this->ernameSearch = (gcnew System::Windows::Forms::Button());
			this->ernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ernameLabel = (gcnew System::Windows::Forms::Label());
			this->eridSearch = (gcnew System::Windows::Forms::Button());
			this->eridTextBox = (gcnew System::Windows::Forms::TextBox());
			this->eridLabel = (gcnew System::Windows::Forms::Label());
			this->showEmployees = (gcnew System::Windows::Forms::CheckBox());
			this->rShowAll = (gcnew System::Windows::Forms::Button());
			this->rSearch = (gcnew System::Windows::Forms::Button());
			this->rcountSearch = (gcnew System::Windows::Forms::Button());
			this->rlocationSearch = (gcnew System::Windows::Forms::Button());
			this->rnameSearch = (gcnew System::Windows::Forms::Button());
			this->ridSearch = (gcnew System::Windows::Forms::Button());
			this->rcountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rcountLabel = (gcnew System::Windows::Forms::Label());
			this->rlocationTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rlocationLabel = (gcnew System::Windows::Forms::Label());
			this->rnameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rnameLabel = (gcnew System::Windows::Forms::Label());
			this->ridTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ridLabel = (gcnew System::Windows::Forms::Label());
			this->modelTab = (gcnew System::Windows::Forms::TabControl());
			this->menuTab = (gcnew System::Windows::Forms::TabPage());
			this->rmSearch = (gcnew System::Windows::Forms::Button());
			this->rmicountSearch = (gcnew System::Windows::Forms::Button());
			this->rmicountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rmicountLabel = (gcnew System::Windows::Forms::Label());
			this->rminameSearch = (gcnew System::Windows::Forms::Button());
			this->rminameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rminameLabel = (gcnew System::Windows::Forms::Label());
			this->rmnameSearch = (gcnew System::Windows::Forms::Button());
			this->rmidSearch = (gcnew System::Windows::Forms::Button());
			this->rmnameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rmnameLabel = (gcnew System::Windows::Forms::Label());
			this->rmidTextBox = (gcnew System::Windows::Forms::TextBox());
			this->rmidLabel = (gcnew System::Windows::Forms::Label());
			this->rmShowAll = (gcnew System::Windows::Forms::Button());
			this->stockStatusBox = (gcnew System::Windows::Forms::GroupBox());
			this->rmstatusSearch = (gcnew System::Windows::Forms::Button());
			this->noStockCh = (gcnew System::Windows::Forms::CheckBox());
			this->loStockCh = (gcnew System::Windows::Forms::CheckBox());
			this->inStockCh = (gcnew System::Windows::Forms::CheckBox());
			this->itemTypeBox = (gcnew System::Windows::Forms::GroupBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->rmiDrinkCh = (gcnew System::Windows::Forms::CheckBox());
			this->rmiFoodCh = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSRC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->empTab->SuspendLayout();
			this->restTab->SuspendLayout();
			this->modelTab->SuspendLayout();
			this->menuTab->SuspendLayout();
			this->stockStatusBox->SuspendLayout();
			this->itemTypeBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->dataGridView->Location = System::Drawing::Point(35, 347);
			this->dataGridView->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->Size = System::Drawing::Size(958, 308);
			this->dataGridView->TabIndex = 2;
			// 
			// empTab
			// 
			this->empTab->BackColor = System::Drawing::Color::Transparent;
			this->empTab->Controls->Add(this->epShowAll);
			this->empTab->Controls->Add(this->pSearch);
			this->empTab->Controls->Add(this->ppaySearch);
			this->empTab->Controls->Add(this->ppayTextBox);
			this->empTab->Controls->Add(this->eSearch);
			this->empTab->Controls->Add(this->ppayLabel);
			this->empTab->Controls->Add(this->pnameSearch);
			this->empTab->Controls->Add(this->pnameTextBox);
			this->empTab->Controls->Add(this->pnameLabel);
			this->empTab->Controls->Add(this->pidSearch);
			this->empTab->Controls->Add(this->pidTextBox);
			this->empTab->Controls->Add(this->pidLabel);
			this->empTab->Controls->Add(this->eaddressSearch);
			this->empTab->Controls->Add(this->eaddressTextBox);
			this->empTab->Controls->Add(this->eaddressLabel);
			this->empTab->Controls->Add(this->enameSearch);
			this->empTab->Controls->Add(this->enameTextBox);
			this->empTab->Controls->Add(this->enameLabel);
			this->empTab->Controls->Add(this->eidSearch);
			this->empTab->Controls->Add(this->eidTextBox);
			this->empTab->Controls->Add(this->eidLabel);
			this->empTab->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->empTab->Location = System::Drawing::Point(4, 23);
			this->empTab->Margin = System::Windows::Forms::Padding(4);
			this->empTab->Name = L"empTab";
			this->empTab->Padding = System::Windows::Forms::Padding(4);
			this->empTab->Size = System::Drawing::Size(954, 298);
			this->empTab->TabIndex = 1;
			this->empTab->Text = L"Employee";
			// 
			// epShowAll
			// 
			this->epShowAll->Location = System::Drawing::Point(858, 253);
			this->epShowAll->Margin = System::Windows::Forms::Padding(4);
			this->epShowAll->Name = L"epShowAll";
			this->epShowAll->Size = System::Drawing::Size(88, 32);
			this->epShowAll->TabIndex = 20;
			this->epShowAll->Text = L"Show All";
			this->epShowAll->UseVisualStyleBackColor = true;
			this->epShowAll->Click += gcnew System::EventHandler(this, &Model::epShowAll_Click);
			// 
			// pSearch
			// 
			this->pSearch->Location = System::Drawing::Point(489, 171);
			this->pSearch->Margin = System::Windows::Forms::Padding(4);
			this->pSearch->Name = L"pSearch";
			this->pSearch->Size = System::Drawing::Size(88, 32);
			this->pSearch->TabIndex = 30;
			this->pSearch->Text = L"Search";
			this->pSearch->UseVisualStyleBackColor = true;
			this->pSearch->Click += gcnew System::EventHandler(this, &Model::pSearch_Click);
			// 
			// ppaySearch
			// 
			this->ppaySearch->Location = System::Drawing::Point(843, 23);
			this->ppaySearch->Margin = System::Windows::Forms::Padding(4);
			this->ppaySearch->Name = L"ppaySearch";
			this->ppaySearch->Size = System::Drawing::Size(88, 26);
			this->ppaySearch->TabIndex = 29;
			this->ppaySearch->Text = L"Search";
			this->ppaySearch->UseVisualStyleBackColor = true;
			this->ppaySearch->Click += gcnew System::EventHandler(this, &Model::ppaySearch_Click);
			// 
			// ppayTextBox
			// 
			this->ppayTextBox->Location = System::Drawing::Point(675, 23);
			this->ppayTextBox->Margin = System::Windows::Forms::Padding(4);
			this->ppayTextBox->Name = L"ppayTextBox";
			this->ppayTextBox->Size = System::Drawing::Size(161, 26);
			this->ppayTextBox->TabIndex = 28;
			// 
			// eSearch
			// 
			this->eSearch->Location = System::Drawing::Point(20, 171);
			this->eSearch->Margin = System::Windows::Forms::Padding(4);
			this->eSearch->Name = L"eSearch";
			this->eSearch->Size = System::Drawing::Size(88, 32);
			this->eSearch->TabIndex = 19;
			this->eSearch->Text = L"Search";
			this->eSearch->UseVisualStyleBackColor = true;
			this->eSearch->Click += gcnew System::EventHandler(this, &Model::eSearch_Click);
			// 
			// ppayLabel
			// 
			this->ppayLabel->AutoSize = true;
			this->ppayLabel->Location = System::Drawing::Point(486, 27);
			this->ppayLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ppayLabel->Name = L"ppayLabel";
			this->ppayLabel->Size = System::Drawing::Size(160, 18);
			this->ppayLabel->TabIndex = 27;
			this->ppayLabel->Text = L"Employee Position Pay:";
			// 
			// pnameSearch
			// 
			this->pnameSearch->Location = System::Drawing::Point(843, 121);
			this->pnameSearch->Margin = System::Windows::Forms::Padding(4);
			this->pnameSearch->Name = L"pnameSearch";
			this->pnameSearch->Size = System::Drawing::Size(88, 26);
			this->pnameSearch->TabIndex = 26;
			this->pnameSearch->Text = L"Search";
			this->pnameSearch->UseVisualStyleBackColor = true;
			this->pnameSearch->Click += gcnew System::EventHandler(this, &Model::pnameSearch_Click);
			// 
			// pnameTextBox
			// 
			this->pnameTextBox->Location = System::Drawing::Point(675, 121);
			this->pnameTextBox->Margin = System::Windows::Forms::Padding(4);
			this->pnameTextBox->Name = L"pnameTextBox";
			this->pnameTextBox->Size = System::Drawing::Size(161, 26);
			this->pnameTextBox->TabIndex = 25;
			// 
			// pnameLabel
			// 
			this->pnameLabel->AutoSize = true;
			this->pnameLabel->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pnameLabel->Location = System::Drawing::Point(486, 124);
			this->pnameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->pnameLabel->Name = L"pnameLabel";
			this->pnameLabel->Size = System::Drawing::Size(153, 16);
			this->pnameLabel->TabIndex = 24;
			this->pnameLabel->Text = L"Employee Position Name:";
			// 
			// pidSearch
			// 
			this->pidSearch->Location = System::Drawing::Point(843, 70);
			this->pidSearch->Margin = System::Windows::Forms::Padding(4);
			this->pidSearch->Name = L"pidSearch";
			this->pidSearch->Size = System::Drawing::Size(88, 26);
			this->pidSearch->TabIndex = 23;
			this->pidSearch->Text = L"Search";
			this->pidSearch->UseVisualStyleBackColor = true;
			this->pidSearch->Click += gcnew System::EventHandler(this, &Model::pidSearch_Click);
			// 
			// pidTextBox
			// 
			this->pidTextBox->Location = System::Drawing::Point(675, 70);
			this->pidTextBox->Margin = System::Windows::Forms::Padding(4);
			this->pidTextBox->Name = L"pidTextBox";
			this->pidTextBox->Size = System::Drawing::Size(161, 26);
			this->pidTextBox->TabIndex = 22;
			// 
			// pidLabel
			// 
			this->pidLabel->AutoSize = true;
			this->pidLabel->Location = System::Drawing::Point(486, 74);
			this->pidLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->pidLabel->Name = L"pidLabel";
			this->pidLabel->Size = System::Drawing::Size(151, 18);
			this->pidLabel->TabIndex = 21;
			this->pidLabel->Text = L"Employee Position ID:";
			// 
			// eaddressSearch
			// 
			this->eaddressSearch->Location = System::Drawing::Point(374, 121);
			this->eaddressSearch->Margin = System::Windows::Forms::Padding(4);
			this->eaddressSearch->Name = L"eaddressSearch";
			this->eaddressSearch->Size = System::Drawing::Size(88, 26);
			this->eaddressSearch->TabIndex = 20;
			this->eaddressSearch->Text = L"Search";
			this->eaddressSearch->UseVisualStyleBackColor = true;
			this->eaddressSearch->Click += gcnew System::EventHandler(this, &Model::eaddressSearch_Click);
			// 
			// eaddressTextBox
			// 
			this->eaddressTextBox->Location = System::Drawing::Point(206, 121);
			this->eaddressTextBox->Margin = System::Windows::Forms::Padding(4);
			this->eaddressTextBox->Name = L"eaddressTextBox";
			this->eaddressTextBox->Size = System::Drawing::Size(161, 26);
			this->eaddressTextBox->TabIndex = 19;
			// 
			// eaddressLabel
			// 
			this->eaddressLabel->AutoSize = true;
			this->eaddressLabel->Location = System::Drawing::Point(17, 124);
			this->eaddressLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->eaddressLabel->Name = L"eaddressLabel";
			this->eaddressLabel->Size = System::Drawing::Size(136, 18);
			this->eaddressLabel->TabIndex = 18;
			this->eaddressLabel->Text = L"Employee Address:";
			// 
			// enameSearch
			// 
			this->enameSearch->Location = System::Drawing::Point(374, 70);
			this->enameSearch->Margin = System::Windows::Forms::Padding(4);
			this->enameSearch->Name = L"enameSearch";
			this->enameSearch->Size = System::Drawing::Size(88, 26);
			this->enameSearch->TabIndex = 17;
			this->enameSearch->Text = L"Search";
			this->enameSearch->UseVisualStyleBackColor = true;
			this->enameSearch->Click += gcnew System::EventHandler(this, &Model::enameSearch_Click);
			// 
			// enameTextBox
			// 
			this->enameTextBox->Location = System::Drawing::Point(206, 70);
			this->enameTextBox->Margin = System::Windows::Forms::Padding(4);
			this->enameTextBox->Name = L"enameTextBox";
			this->enameTextBox->Size = System::Drawing::Size(161, 26);
			this->enameTextBox->TabIndex = 16;
			// 
			// enameLabel
			// 
			this->enameLabel->AutoSize = true;
			this->enameLabel->Location = System::Drawing::Point(17, 74);
			this->enameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->enameLabel->Name = L"enameLabel";
			this->enameLabel->Size = System::Drawing::Size(120, 18);
			this->enameLabel->TabIndex = 15;
			this->enameLabel->Text = L"Employee Name:";
			// 
			// eidSearch
			// 
			this->eidSearch->Location = System::Drawing::Point(374, 20);
			this->eidSearch->Margin = System::Windows::Forms::Padding(4);
			this->eidSearch->Name = L"eidSearch";
			this->eidSearch->Size = System::Drawing::Size(88, 26);
			this->eidSearch->TabIndex = 14;
			this->eidSearch->Text = L"Search";
			this->eidSearch->UseVisualStyleBackColor = true;
			this->eidSearch->Click += gcnew System::EventHandler(this, &Model::eidSearch_Click);
			// 
			// eidTextBox
			// 
			this->eidTextBox->Location = System::Drawing::Point(206, 20);
			this->eidTextBox->Margin = System::Windows::Forms::Padding(4);
			this->eidTextBox->Name = L"eidTextBox";
			this->eidTextBox->Size = System::Drawing::Size(161, 26);
			this->eidTextBox->TabIndex = 13;
			// 
			// eidLabel
			// 
			this->eidLabel->AutoSize = true;
			this->eidLabel->Location = System::Drawing::Point(17, 23);
			this->eidLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->eidLabel->Name = L"eidLabel";
			this->eidLabel->Size = System::Drawing::Size(94, 18);
			this->eidLabel->TabIndex = 12;
			this->eidLabel->Text = L"Employee ID:";
			// 
			// restTab
			// 
			this->restTab->BackColor = System::Drawing::Color::Transparent;
			this->restTab->Controls->Add(this->eraddrSearch);
			this->restTab->Controls->Add(this->eraddrTextBox);
			this->restTab->Controls->Add(this->eraddrLabel);
			this->restTab->Controls->Add(this->ernameSearch);
			this->restTab->Controls->Add(this->ernameTextBox);
			this->restTab->Controls->Add(this->ernameLabel);
			this->restTab->Controls->Add(this->eridSearch);
			this->restTab->Controls->Add(this->eridTextBox);
			this->restTab->Controls->Add(this->eridLabel);
			this->restTab->Controls->Add(this->showEmployees);
			this->restTab->Controls->Add(this->rShowAll);
			this->restTab->Controls->Add(this->rSearch);
			this->restTab->Controls->Add(this->rcountSearch);
			this->restTab->Controls->Add(this->rlocationSearch);
			this->restTab->Controls->Add(this->rnameSearch);
			this->restTab->Controls->Add(this->ridSearch);
			this->restTab->Controls->Add(this->rcountTextBox);
			this->restTab->Controls->Add(this->rcountLabel);
			this->restTab->Controls->Add(this->rlocationTextBox);
			this->restTab->Controls->Add(this->rlocationLabel);
			this->restTab->Controls->Add(this->rnameTextBox);
			this->restTab->Controls->Add(this->rnameLabel);
			this->restTab->Controls->Add(this->ridTextBox);
			this->restTab->Controls->Add(this->ridLabel);
			this->restTab->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->restTab->Location = System::Drawing::Point(4, 23);
			this->restTab->Margin = System::Windows::Forms::Padding(4);
			this->restTab->Name = L"restTab";
			this->restTab->Padding = System::Windows::Forms::Padding(4);
			this->restTab->Size = System::Drawing::Size(954, 298);
			this->restTab->TabIndex = 0;
			this->restTab->Text = L"Restaurant";
			// 
			// eraddrSearch
			// 
			this->eraddrSearch->Enabled = false;
			this->eraddrSearch->Location = System::Drawing::Point(841, 121);
			this->eraddrSearch->Margin = System::Windows::Forms::Padding(4);
			this->eraddrSearch->Name = L"eraddrSearch";
			this->eraddrSearch->Size = System::Drawing::Size(88, 26);
			this->eraddrSearch->TabIndex = 29;
			this->eraddrSearch->Text = L"Search";
			this->eraddrSearch->UseVisualStyleBackColor = true;
			this->eraddrSearch->Click += gcnew System::EventHandler(this, &Model::eraddrSearch_Click);
			// 
			// eraddrTextBox
			// 
			this->eraddrTextBox->Enabled = false;
			this->eraddrTextBox->Location = System::Drawing::Point(673, 121);
			this->eraddrTextBox->Margin = System::Windows::Forms::Padding(4);
			this->eraddrTextBox->Name = L"eraddrTextBox";
			this->eraddrTextBox->Size = System::Drawing::Size(161, 26);
			this->eraddrTextBox->TabIndex = 28;
			// 
			// eraddrLabel
			// 
			this->eraddrLabel->AutoSize = true;
			this->eraddrLabel->Location = System::Drawing::Point(484, 124);
			this->eraddrLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->eraddrLabel->Name = L"eraddrLabel";
			this->eraddrLabel->Size = System::Drawing::Size(136, 18);
			this->eraddrLabel->TabIndex = 27;
			this->eraddrLabel->Text = L"Employee Address:";
			// 
			// ernameSearch
			// 
			this->ernameSearch->Enabled = false;
			this->ernameSearch->Location = System::Drawing::Point(841, 70);
			this->ernameSearch->Margin = System::Windows::Forms::Padding(4);
			this->ernameSearch->Name = L"ernameSearch";
			this->ernameSearch->Size = System::Drawing::Size(88, 26);
			this->ernameSearch->TabIndex = 26;
			this->ernameSearch->Text = L"Search";
			this->ernameSearch->UseVisualStyleBackColor = true;
			this->ernameSearch->Click += gcnew System::EventHandler(this, &Model::ernameSearch_Click);
			// 
			// ernameTextBox
			// 
			this->ernameTextBox->Enabled = false;
			this->ernameTextBox->Location = System::Drawing::Point(673, 70);
			this->ernameTextBox->Margin = System::Windows::Forms::Padding(4);
			this->ernameTextBox->Name = L"ernameTextBox";
			this->ernameTextBox->Size = System::Drawing::Size(161, 26);
			this->ernameTextBox->TabIndex = 25;
			// 
			// ernameLabel
			// 
			this->ernameLabel->AutoSize = true;
			this->ernameLabel->Location = System::Drawing::Point(484, 74);
			this->ernameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ernameLabel->Name = L"ernameLabel";
			this->ernameLabel->Size = System::Drawing::Size(120, 18);
			this->ernameLabel->TabIndex = 24;
			this->ernameLabel->Text = L"Employee Name:";
			// 
			// eridSearch
			// 
			this->eridSearch->Enabled = false;
			this->eridSearch->Location = System::Drawing::Point(841, 20);
			this->eridSearch->Margin = System::Windows::Forms::Padding(4);
			this->eridSearch->Name = L"eridSearch";
			this->eridSearch->Size = System::Drawing::Size(88, 26);
			this->eridSearch->TabIndex = 23;
			this->eridSearch->Text = L"Search";
			this->eridSearch->UseVisualStyleBackColor = true;
			this->eridSearch->Click += gcnew System::EventHandler(this, &Model::eridSearch_Click);
			// 
			// eridTextBox
			// 
			this->eridTextBox->Enabled = false;
			this->eridTextBox->Location = System::Drawing::Point(673, 20);
			this->eridTextBox->Margin = System::Windows::Forms::Padding(4);
			this->eridTextBox->Name = L"eridTextBox";
			this->eridTextBox->Size = System::Drawing::Size(161, 26);
			this->eridTextBox->TabIndex = 22;
			// 
			// eridLabel
			// 
			this->eridLabel->AutoSize = true;
			this->eridLabel->Location = System::Drawing::Point(484, 23);
			this->eridLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->eridLabel->Name = L"eridLabel";
			this->eridLabel->Size = System::Drawing::Size(94, 18);
			this->eridLabel->TabIndex = 21;
			this->eridLabel->Text = L"Employee ID:";
			// 
			// showEmployees
			// 
			this->showEmployees->AutoSize = true;
			this->showEmployees->Location = System::Drawing::Point(22, 269);
			this->showEmployees->Name = L"showEmployees";
			this->showEmployees->Size = System::Drawing::Size(141, 22);
			this->showEmployees->TabIndex = 20;
			this->showEmployees->Text = L"Show Employees";
			this->showEmployees->UseVisualStyleBackColor = true;
			this->showEmployees->CheckedChanged += gcnew System::EventHandler(this, &Model::showEmployees_CheckedChanged);
			// 
			// rShowAll
			// 
			this->rShowAll->Location = System::Drawing::Point(858, 253);
			this->rShowAll->Margin = System::Windows::Forms::Padding(4);
			this->rShowAll->Name = L"rShowAll";
			this->rShowAll->Size = System::Drawing::Size(88, 32);
			this->rShowAll->TabIndex = 19;
			this->rShowAll->Text = L"Show All";
			this->rShowAll->UseVisualStyleBackColor = true;
			this->rShowAll->Click += gcnew System::EventHandler(this, &Model::rShowAll_Click);
			// 
			// rSearch
			// 
			this->rSearch->Location = System::Drawing::Point(20, 224);
			this->rSearch->Margin = System::Windows::Forms::Padding(4);
			this->rSearch->Name = L"rSearch";
			this->rSearch->Size = System::Drawing::Size(88, 32);
			this->rSearch->TabIndex = 15;
			this->rSearch->Text = L"Search";
			this->rSearch->UseVisualStyleBackColor = true;
			this->rSearch->Click += gcnew System::EventHandler(this, &Model::rSearch_Click);
			// 
			// rcountSearch
			// 
			this->rcountSearch->Location = System::Drawing::Point(374, 172);
			this->rcountSearch->Margin = System::Windows::Forms::Padding(4);
			this->rcountSearch->Name = L"rcountSearch";
			this->rcountSearch->Size = System::Drawing::Size(88, 26);
			this->rcountSearch->TabIndex = 14;
			this->rcountSearch->Text = L"Search";
			this->rcountSearch->UseVisualStyleBackColor = true;
			this->rcountSearch->Click += gcnew System::EventHandler(this, &Model::rcountSearch_Click);
			// 
			// rlocationSearch
			// 
			this->rlocationSearch->Location = System::Drawing::Point(374, 119);
			this->rlocationSearch->Margin = System::Windows::Forms::Padding(4);
			this->rlocationSearch->Name = L"rlocationSearch";
			this->rlocationSearch->Size = System::Drawing::Size(88, 28);
			this->rlocationSearch->TabIndex = 13;
			this->rlocationSearch->Text = L"Search";
			this->rlocationSearch->UseVisualStyleBackColor = true;
			this->rlocationSearch->Click += gcnew System::EventHandler(this, &Model::rlocationSearch_Click);
			// 
			// rnameSearch
			// 
			this->rnameSearch->Location = System::Drawing::Point(374, 70);
			this->rnameSearch->Margin = System::Windows::Forms::Padding(4);
			this->rnameSearch->Name = L"rnameSearch";
			this->rnameSearch->Size = System::Drawing::Size(88, 26);
			this->rnameSearch->TabIndex = 12;
			this->rnameSearch->Text = L"Search";
			this->rnameSearch->UseVisualStyleBackColor = true;
			this->rnameSearch->Click += gcnew System::EventHandler(this, &Model::rnameSearch_Click);
			// 
			// ridSearch
			// 
			this->ridSearch->Location = System::Drawing::Point(374, 20);
			this->ridSearch->Margin = System::Windows::Forms::Padding(4);
			this->ridSearch->Name = L"ridSearch";
			this->ridSearch->Size = System::Drawing::Size(88, 26);
			this->ridSearch->TabIndex = 11;
			this->ridSearch->Text = L"Search";
			this->ridSearch->UseVisualStyleBackColor = true;
			this->ridSearch->Click += gcnew System::EventHandler(this, &Model::ridSearch_Click);
			// 
			// rcountTextBox
			// 
			this->rcountTextBox->Location = System::Drawing::Point(206, 172);
			this->rcountTextBox->Margin = System::Windows::Forms::Padding(4);
			this->rcountTextBox->Name = L"rcountTextBox";
			this->rcountTextBox->Size = System::Drawing::Size(161, 26);
			this->rcountTextBox->TabIndex = 10;
			// 
			// rcountLabel
			// 
			this->rcountLabel->AutoSize = true;
			this->rcountLabel->Location = System::Drawing::Point(17, 176);
			this->rcountLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->rcountLabel->Name = L"rcountLabel";
			this->rcountLabel->Size = System::Drawing::Size(118, 18);
			this->rcountLabel->TabIndex = 9;
			this->rcountLabel->Text = L"Employee Count:";
			// 
			// rlocationTextBox
			// 
			this->rlocationTextBox->Location = System::Drawing::Point(206, 121);
			this->rlocationTextBox->Margin = System::Windows::Forms::Padding(4);
			this->rlocationTextBox->Name = L"rlocationTextBox";
			this->rlocationTextBox->Size = System::Drawing::Size(161, 26);
			this->rlocationTextBox->TabIndex = 8;
			// 
			// rlocationLabel
			// 
			this->rlocationLabel->AutoSize = true;
			this->rlocationLabel->Location = System::Drawing::Point(17, 124);
			this->rlocationLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->rlocationLabel->Name = L"rlocationLabel";
			this->rlocationLabel->Size = System::Drawing::Size(146, 18);
			this->rlocationLabel->TabIndex = 7;
			this->rlocationLabel->Text = L"Restaurant Location:";
			// 
			// rnameTextBox
			// 
			this->rnameTextBox->Location = System::Drawing::Point(206, 70);
			this->rnameTextBox->Margin = System::Windows::Forms::Padding(4);
			this->rnameTextBox->Name = L"rnameTextBox";
			this->rnameTextBox->Size = System::Drawing::Size(161, 26);
			this->rnameTextBox->TabIndex = 6;
			// 
			// rnameLabel
			// 
			this->rnameLabel->AutoSize = true;
			this->rnameLabel->Location = System::Drawing::Point(17, 74);
			this->rnameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->rnameLabel->Name = L"rnameLabel";
			this->rnameLabel->Size = System::Drawing::Size(129, 18);
			this->rnameLabel->TabIndex = 5;
			this->rnameLabel->Text = L"Restaurant Name:";
			// 
			// ridTextBox
			// 
			this->ridTextBox->Location = System::Drawing::Point(206, 20);
			this->ridTextBox->Margin = System::Windows::Forms::Padding(4);
			this->ridTextBox->Name = L"ridTextBox";
			this->ridTextBox->Size = System::Drawing::Size(161, 26);
			this->ridTextBox->TabIndex = 4;
			// 
			// ridLabel
			// 
			this->ridLabel->AutoSize = true;
			this->ridLabel->Location = System::Drawing::Point(17, 23);
			this->ridLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->ridLabel->Name = L"ridLabel";
			this->ridLabel->Size = System::Drawing::Size(103, 18);
			this->ridLabel->TabIndex = 3;
			this->ridLabel->Text = L"Restaurant ID:";
			// 
			// modelTab
			// 
			this->modelTab->Controls->Add(this->restTab);
			this->modelTab->Controls->Add(this->empTab);
			this->modelTab->Controls->Add(this->menuTab);
			this->modelTab->Enabled = conStr != "UNDEFINED";
			this->modelTab->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->modelTab->Location = System::Drawing::Point(35, 15);
			this->modelTab->Margin = System::Windows::Forms::Padding(4);
			this->modelTab->Name = L"modelTab";
			this->modelTab->SelectedIndex = 0;
			this->modelTab->Size = System::Drawing::Size(962, 325);
			this->modelTab->TabIndex = 3;
			// 
			// menuTab
			// 
			this->menuTab->BackColor = System::Drawing::Color::Transparent;
			this->menuTab->Controls->Add(this->rmSearch);
			this->menuTab->Controls->Add(this->rmicountSearch);
			this->menuTab->Controls->Add(this->rmicountTextBox);
			this->menuTab->Controls->Add(this->rmicountLabel);
			this->menuTab->Controls->Add(this->rminameSearch);
			this->menuTab->Controls->Add(this->rminameTextBox);
			this->menuTab->Controls->Add(this->rminameLabel);
			this->menuTab->Controls->Add(this->rmnameSearch);
			this->menuTab->Controls->Add(this->rmidSearch);
			this->menuTab->Controls->Add(this->rmnameTextBox);
			this->menuTab->Controls->Add(this->rmnameLabel);
			this->menuTab->Controls->Add(this->rmidTextBox);
			this->menuTab->Controls->Add(this->rmidLabel);
			this->menuTab->Controls->Add(this->rmShowAll);
			this->menuTab->Controls->Add(this->stockStatusBox);
			this->menuTab->Controls->Add(this->itemTypeBox);
			this->menuTab->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuTab->Location = System::Drawing::Point(4, 23);
			this->menuTab->Margin = System::Windows::Forms::Padding(4);
			this->menuTab->Name = L"menuTab";
			this->menuTab->Size = System::Drawing::Size(954, 298);
			this->menuTab->TabIndex = 2;
			this->menuTab->Text = L"Menu";
			// 
			// rmSearch
			// 
			this->rmSearch->Location = System::Drawing::Point(8, 253);
			this->rmSearch->Margin = System::Windows::Forms::Padding(4);
			this->rmSearch->Name = L"rmSearch";
			this->rmSearch->Size = System::Drawing::Size(88, 32);
			this->rmSearch->TabIndex = 36;
			this->rmSearch->Text = L"Search";
			this->rmSearch->UseVisualStyleBackColor = true;
			this->rmSearch->Click += gcnew System::EventHandler(this, &Model::rmSearch_Click);
			// 
			// rmicountSearch
			// 
			this->rmicountSearch->Location = System::Drawing::Point(841, 70);
			this->rmicountSearch->Margin = System::Windows::Forms::Padding(4);
			this->rmicountSearch->Name = L"rmicountSearch";
			this->rmicountSearch->Size = System::Drawing::Size(88, 26);
			this->rmicountSearch->TabIndex = 35;
			this->rmicountSearch->Text = L"Search";
			this->rmicountSearch->UseVisualStyleBackColor = true;
			this->rmicountSearch->Click += gcnew System::EventHandler(this, &Model::rmicountSearch_Click);
			// 
			// rmicountTextBox
			// 
			this->rmicountTextBox->Location = System::Drawing::Point(673, 70);
			this->rmicountTextBox->Margin = System::Windows::Forms::Padding(4);
			this->rmicountTextBox->Name = L"rmicountTextBox";
			this->rmicountTextBox->Size = System::Drawing::Size(161, 26);
			this->rmicountTextBox->TabIndex = 34;
			// 
			// rmicountLabel
			// 
			this->rmicountLabel->AutoSize = true;
			this->rmicountLabel->Location = System::Drawing::Point(484, 74);
			this->rmicountLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->rmicountLabel->Name = L"rmicountLabel";
			this->rmicountLabel->Size = System::Drawing::Size(83, 18);
			this->rmicountLabel->TabIndex = 33;
			this->rmicountLabel->Text = L"Item Count:";
			// 
			// rminameSearch
			// 
			this->rminameSearch->Location = System::Drawing::Point(841, 20);
			this->rminameSearch->Margin = System::Windows::Forms::Padding(4);
			this->rminameSearch->Name = L"rminameSearch";
			this->rminameSearch->Size = System::Drawing::Size(88, 26);
			this->rminameSearch->TabIndex = 32;
			this->rminameSearch->Text = L"Search";
			this->rminameSearch->UseVisualStyleBackColor = true;
			this->rminameSearch->Click += gcnew System::EventHandler(this, &Model::rminameSearch_Click);
			// 
			// rminameTextBox
			// 
			this->rminameTextBox->Location = System::Drawing::Point(673, 20);
			this->rminameTextBox->Margin = System::Windows::Forms::Padding(4);
			this->rminameTextBox->Name = L"rminameTextBox";
			this->rminameTextBox->Size = System::Drawing::Size(161, 26);
			this->rminameTextBox->TabIndex = 31;
			// 
			// rminameLabel
			// 
			this->rminameLabel->AutoSize = true;
			this->rminameLabel->Location = System::Drawing::Point(484, 23);
			this->rminameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->rminameLabel->Name = L"rminameLabel";
			this->rminameLabel->Size = System::Drawing::Size(85, 18);
			this->rminameLabel->TabIndex = 30;
			this->rminameLabel->Text = L"Item Name:";
			// 
			// rmnameSearch
			// 
			this->rmnameSearch->Location = System::Drawing::Point(374, 70);
			this->rmnameSearch->Margin = System::Windows::Forms::Padding(4);
			this->rmnameSearch->Name = L"rmnameSearch";
			this->rmnameSearch->Size = System::Drawing::Size(88, 26);
			this->rmnameSearch->TabIndex = 29;
			this->rmnameSearch->Text = L"Search";
			this->rmnameSearch->UseVisualStyleBackColor = true;
			this->rmnameSearch->Click += gcnew System::EventHandler(this, &Model::rmnameSearch_Click);
			// 
			// rmidSearch
			// 
			this->rmidSearch->Location = System::Drawing::Point(374, 20);
			this->rmidSearch->Margin = System::Windows::Forms::Padding(4);
			this->rmidSearch->Name = L"rmidSearch";
			this->rmidSearch->Size = System::Drawing::Size(88, 26);
			this->rmidSearch->TabIndex = 28;
			this->rmidSearch->Text = L"Search";
			this->rmidSearch->UseVisualStyleBackColor = true;
			this->rmidSearch->Click += gcnew System::EventHandler(this, &Model::rmidSearch_Click);
			// 
			// rmnameTextBox
			// 
			this->rmnameTextBox->Location = System::Drawing::Point(206, 70);
			this->rmnameTextBox->Margin = System::Windows::Forms::Padding(4);
			this->rmnameTextBox->Name = L"rmnameTextBox";
			this->rmnameTextBox->Size = System::Drawing::Size(161, 26);
			this->rmnameTextBox->TabIndex = 27;
			// 
			// rmnameLabel
			// 
			this->rmnameLabel->AutoSize = true;
			this->rmnameLabel->Location = System::Drawing::Point(17, 74);
			this->rmnameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->rmnameLabel->Name = L"rmnameLabel";
			this->rmnameLabel->Size = System::Drawing::Size(129, 18);
			this->rmnameLabel->TabIndex = 26;
			this->rmnameLabel->Text = L"Restaurant Name:";
			// 
			// rmidTextBox
			// 
			this->rmidTextBox->Location = System::Drawing::Point(206, 20);
			this->rmidTextBox->Margin = System::Windows::Forms::Padding(4);
			this->rmidTextBox->Name = L"rmidTextBox";
			this->rmidTextBox->Size = System::Drawing::Size(161, 26);
			this->rmidTextBox->TabIndex = 25;
			// 
			// rmidLabel
			// 
			this->rmidLabel->AutoSize = true;
			this->rmidLabel->Location = System::Drawing::Point(17, 23);
			this->rmidLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->rmidLabel->Name = L"rmidLabel";
			this->rmidLabel->Size = System::Drawing::Size(103, 18);
			this->rmidLabel->TabIndex = 24;
			this->rmidLabel->Text = L"Restaurant ID:";
			// 
			// rmShowAll
			// 
			this->rmShowAll->Location = System::Drawing::Point(858, 253);
			this->rmShowAll->Margin = System::Windows::Forms::Padding(4);
			this->rmShowAll->Name = L"rmShowAll";
			this->rmShowAll->Size = System::Drawing::Size(88, 32);
			this->rmShowAll->TabIndex = 21;
			this->rmShowAll->Text = L"Show All";
			this->rmShowAll->UseVisualStyleBackColor = true;
			this->rmShowAll->Click += gcnew System::EventHandler(this, &Model::rmShowAll_Click);
			// 
			// stockStatusBox
			// 
			this->stockStatusBox->Controls->Add(this->rmstatusSearch);
			this->stockStatusBox->Controls->Add(this->noStockCh);
			this->stockStatusBox->Controls->Add(this->loStockCh);
			this->stockStatusBox->Controls->Add(this->inStockCh);
			this->stockStatusBox->Location = System::Drawing::Point(20, 120);
			this->stockStatusBox->Name = L"stockStatusBox";
			this->stockStatusBox->Size = System::Drawing::Size(442, 113);
			this->stockStatusBox->TabIndex = 2;
			this->stockStatusBox->TabStop = false;
			this->stockStatusBox->Text = L"Stock Status";
			// 
			// rmstatusSearch
			// 
			this->rmstatusSearch->Location = System::Drawing::Point(347, 80);
			this->rmstatusSearch->Margin = System::Windows::Forms::Padding(4);
			this->rmstatusSearch->Name = L"rmstatusSearch";
			this->rmstatusSearch->Size = System::Drawing::Size(88, 26);
			this->rmstatusSearch->TabIndex = 36;
			this->rmstatusSearch->Text = L"Search";
			this->rmstatusSearch->UseVisualStyleBackColor = true;
			this->rmstatusSearch->Click += gcnew System::EventHandler(this, &Model::rmstatusSearch_Click);
			// 
			// noStockCh
			// 
			this->noStockCh->AutoSize = true;
			this->noStockCh->Location = System::Drawing::Point(7, 85);
			this->noStockCh->Name = L"noStockCh";
			this->noStockCh->Size = System::Drawing::Size(87, 22);
			this->noStockCh->TabIndex = 4;
			this->noStockCh->Text = L"No Stock";
			this->noStockCh->UseVisualStyleBackColor = true;
			this->noStockCh->CheckedChanged += gcnew System::EventHandler(this, &Model::noStockCh_CheckedChanged);
			// 
			// loStockCh
			// 
			this->loStockCh->AutoSize = true;
			this->loStockCh->Location = System::Drawing::Point(6, 57);
			this->loStockCh->Name = L"loStockCh";
			this->loStockCh->Size = System::Drawing::Size(97, 22);
			this->loStockCh->TabIndex = 3;
			this->loStockCh->Text = L"Low Stock";
			this->loStockCh->UseVisualStyleBackColor = true;
			this->loStockCh->CheckedChanged += gcnew System::EventHandler(this, &Model::loStockCh_CheckedChanged);
			// 
			// inStockCh
			// 
			this->inStockCh->AutoSize = true;
			this->inStockCh->Location = System::Drawing::Point(6, 29);
			this->inStockCh->Name = L"inStockCh";
			this->inStockCh->Size = System::Drawing::Size(80, 22);
			this->inStockCh->TabIndex = 2;
			this->inStockCh->Text = L"In Stock";
			this->inStockCh->UseVisualStyleBackColor = true;
			this->inStockCh->CheckedChanged += gcnew System::EventHandler(this, &Model::inStockCh_CheckedChanged);
			// 
			// itemTypeBox
			// 
			this->itemTypeBox->Controls->Add(this->button7);
			this->itemTypeBox->Controls->Add(this->rmiDrinkCh);
			this->itemTypeBox->Controls->Add(this->rmiFoodCh);
			this->itemTypeBox->Location = System::Drawing::Point(487, 120);
			this->itemTypeBox->Name = L"itemTypeBox";
			this->itemTypeBox->Size = System::Drawing::Size(442, 113);
			this->itemTypeBox->TabIndex = 1;
			this->itemTypeBox->TabStop = false;
			this->itemTypeBox->Text = L"Item Type";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(347, 80);
			this->button7->Margin = System::Windows::Forms::Padding(4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(88, 26);
			this->button7->TabIndex = 37;
			this->button7->Text = L"Search";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Model::button7_Click);
			// 
			// rmiDrinkCh
			// 
			this->rmiDrinkCh->AutoSize = true;
			this->rmiDrinkCh->Location = System::Drawing::Point(6, 53);
			this->rmiDrinkCh->Name = L"rmiDrinkCh";
			this->rmiDrinkCh->Size = System::Drawing::Size(63, 22);
			this->rmiDrinkCh->TabIndex = 1;
			this->rmiDrinkCh->Text = L"Drink";
			this->rmiDrinkCh->UseVisualStyleBackColor = true;
			this->rmiDrinkCh->CheckedChanged += gcnew System::EventHandler(this, &Model::rmiDrinkCh_CheckedChanged);
			// 
			// rmiFoodCh
			// 
			this->rmiFoodCh->AutoSize = true;
			this->rmiFoodCh->Location = System::Drawing::Point(6, 25);
			this->rmiFoodCh->Name = L"rmiFoodCh";
			this->rmiFoodCh->Size = System::Drawing::Size(59, 22);
			this->rmiFoodCh->TabIndex = 0;
			this->rmiFoodCh->Text = L"Food";
			this->rmiFoodCh->UseVisualStyleBackColor = true;
			this->rmiFoodCh->CheckedChanged += gcnew System::EventHandler(this, &Model::rmiFoodCh_CheckedChanged);
			// 
			// Model
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1032, 693);
			this->Controls->Add(this->modelTab);
			this->Controls->Add(this->dataGridView);
			this->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1048, 732);
			this->MinimumSize = System::Drawing::Size(1048, 732);
			this->Name = L"Model";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CS470: Restaurant Database ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSRC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->empTab->ResumeLayout(false);
			this->empTab->PerformLayout();
			this->restTab->ResumeLayout(false);
			this->restTab->PerformLayout();
			this->modelTab->ResumeLayout(false);
			this->menuTab->ResumeLayout(false);
			this->menuTab->PerformLayout();
			this->stockStatusBox->ResumeLayout(false);
			this->stockStatusBox->PerformLayout();
			this->itemTypeBox->ResumeLayout(false);
			this->itemTypeBox->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
	// RETURNS CONNECTION STR
	private: System::String^ InitializeConnection() {
		try {
			String^ conStr = System::Configuration::ConfigurationManager::AppSettings[0];
			MySqlConnection^ con = gcnew MySqlConnection(conStr);

			// Test the data
			MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("SELECT * FROM restaurant ORDER BY restaurantID", con);
			DataTable^ dt = gcnew DataTable();
			sda->Fill(dt);

			return conStr;
		}

		catch (Exception ^ ex) {
			MessageBox::Show(ex->Message, "Error:");
			return "UNDEFINED";
		}
	}

	// RETURNS TRUE IF THE STRING CONTAINS ILLEGAL CHARACTERS
	private: bool containsIllegal(String^ in) {
		String^ illegalChars = "();'";
		for (int i = 0; i < illegalChars->Length; i++) {
			for (int j = 0; j < in->Length; j++) {
				char illChar = illegalChars[i];
				char ptrChar = in[j];

				if (ptrChar == illChar) {
					return true;
				}
			}
		}
		return false;
	}

	// SHOWS/HIDES EMPLOYEE FUNCTIONS
	private: System::Void showEmployees_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Boolean mode = showEmployees->Checked;

		rcountTextBox->Enabled = !mode;
		rcountSearch->Enabled = !mode;

		eridTextBox->Enabled = mode;
		eridSearch->Enabled = mode;

		ernameTextBox->Enabled = mode;
		ernameSearch->Enabled = mode;

		eraddrTextBox->Enabled = mode;
		eraddrSearch->Enabled = mode;
	}

//
// RESTAURANT SEARCH FUNCTIONS
//
private: System::Void rSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ ID = ridTextBox->Text;
		String^ Name = rnameTextBox->Text;
		String^ Locat = rlocationTextBox->Text;
		String^ Count = rcountTextBox->Text;

		if (ID == "" || Name == "" || Locat == "" || Count == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(ID) || containsIllegal(Name) || containsIllegal(Locat) || containsIllegal(Count)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda;

		if (showEmployees->Checked == false)
			sda = gcnew MySqlDataAdapter("CALL SearchRestaurant(" + ID + ", '" + Name + "', '" + Locat + "', " + Count + ")", con);

		else {
			String^ eID = eridTextBox->Text;
			String^ eName = ernameTextBox->Text;
			String^ eAddr = eraddrTextBox->Text;

			if (eID == "" || eName == "" || eAddr == "") {
				MessageBox::Show("Empty fields.", "Notice:");
				return;
			}

			if (containsIllegal(eID) || containsIllegal(eName) || containsIllegal(eAddr)) {
				MessageBox::Show("Input contains illegal characters.", "Notice:");
				return;
			}

			sda = gcnew MySqlDataAdapter("CALL SearchRestaurantEmp(" + ID + ", '" + Name + "', '" + Locat + "', "+eID+", '"+eName+"', '"+eAddr+"')", con);
		}

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void ridSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ ID = ridTextBox->Text;

		if (ID == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(ID)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda;
		
		if (showEmployees->Checked == false)
			sda = gcnew MySqlDataAdapter("CALL SearchRestaurantID(" + ID + ")", con);

		else 
			sda = gcnew MySqlDataAdapter("CALL SearchRestaurantIDEmp(" + ID + ")", con);
		

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void rnameSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ Name = rnameTextBox->Text;

		if (Name == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(Name)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda;
			
		if (showEmployees->Checked == false)
			sda = gcnew MySqlDataAdapter("CALL SearchRestaurantName('" + Name + "')", con);

		else 
			sda = gcnew MySqlDataAdapter("CALL SearchRestaurantNameEmp('" + Name + "')", con);
		

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void rlocationSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ Locat = rlocationTextBox->Text;

		if (Locat == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(Locat)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda;
		
		if (showEmployees->Checked == false)
			sda = gcnew MySqlDataAdapter("CALL SearchRestaurantLoc('" + Locat + "')", con);

		else
			sda = gcnew MySqlDataAdapter("CALL SearchRestaurantLocEmp('" + Locat + "')", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void rcountSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ Count = rcountTextBox->Text;

		if (Count == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(Count)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRestaurantCnt(" + Count + ")", con);


		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void rShowAll_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda;
		
		if (showEmployees->Checked == false)
			sda = gcnew MySqlDataAdapter("CALL ShowAllRestaurant()", con);

		else
			sda = gcnew MySqlDataAdapter("CALL ShowAllRestaurantEmp()", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}

//
// EMPLOYEE SEARCH FUNCTIONS
//
private: System::Void eidSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ ID = eidTextBox->Text;

		if (ID == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(ID)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchEmployeeID(" + ID + ")", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void enameSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ Name = enameTextBox->Text;

		if (Name == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(Name)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchEmployeeName('" + Name + "')", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void eaddressSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ Addr = eaddressTextBox->Text;

		if (Addr == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(Addr)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchEmployeeAddr('" + Addr + "')", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void eSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ ID = eidTextBox->Text;
		String^ Name = enameTextBox->Text;
		String^ Addr = eaddressTextBox->Text;

		if (ID == "" || Name == "" || Addr == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(ID) || containsIllegal(Name) || containsIllegal(Addr)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchEmployee("+ID+", '"+Name+"', '"+Addr+"')", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}

//
// POSITION SEARCH FUNCTIONS
//
private: System::Void ppaySearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ Pay = ppayTextBox->Text;

		if (Pay == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(Pay)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchPositionPay(" + Pay + ")", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void pidSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ ID = pidTextBox->Text;

		if (ID == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(ID)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchPositionID(" + ID + ")", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void pnameSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ Title = pnameTextBox->Text;

		if (Title == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(Title)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchPositionTitle('" + Title + "')", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void pSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ ID = pidTextBox->Text;
		String^ Title = pnameTextBox->Text;
		String^ Pay = ppayTextBox->Text;

		if (ID == "" || Title == "" || Pay == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(ID) || containsIllegal(Title) || containsIllegal(Pay)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchPosition("+ID+", '"+Title+"', "+Pay+")", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}

//
// EMPLOYEE & POSITION FUNCTIONS
//
private: System::Void epShowAll_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("SELECT * FROM employee INNER JOIN position ON employee.employeePosition = position.positionID ORDER BY employeeID, positionID", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}

//
// EMPLOYEE & RESTAURANT FUNCTIONS
//
private: System::Void eridSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ eID = eridTextBox->Text;

		if (eID == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(eID)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRestaurantEmpID(" + eID + ")", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void ernameSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ eName = ernameTextBox->Text;

		if (eName == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(eName)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRestaurantEmpName('" + eName + "')", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void eraddrSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ eAddr = eraddrTextBox->Text;

		if (eAddr == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(eAddr)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRestaurantEmpAddr('" + eAddr + "')", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}

//
// RESTAURANT & MENU CHECK BOXES
//
private: System::Void inStockCh_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (loStockCh->Checked == true) loStockCh->Checked = false;
	if (noStockCh->Checked == true) noStockCh->Checked = false;
}

private: System::Void loStockCh_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (inStockCh->Checked == true) inStockCh->Checked = false;
	if (noStockCh->Checked == true) noStockCh->Checked = false;
}

private: System::Void noStockCh_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (inStockCh->Checked == true) inStockCh->Checked = false;
	if (loStockCh->Checked == true) loStockCh->Checked = false;
}
private: System::String^ getActiveStockCh() {
	String^ active = "%";
	if (inStockCh->Checked == true) active = "in_stock";
	else if (loStockCh->Checked == true) active = "lo_stock";
	else if (noStockCh->Checked == true) active = "no_stock";
	return active;
}
private: System::Void rmiFoodCh_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (rmiDrinkCh->Checked == true) rmiDrinkCh->Checked = false;
}
private: System::Void rmiDrinkCh_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (rmiFoodCh->Checked == true) rmiFoodCh->Checked = false;
}
private: System::String^ getActiveTypeCh() {
	String^ active = "%";
	if (rmiFoodCh->Checked == true) active = "Food";
	else if (rmiDrinkCh->Checked == true) active = "Drink";
	return active;
}

//
// RESTAURANT & MENU FUNCTIONS
//
private: System::Void rmShowAll_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL ShowAllRM()", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void rmSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ rID = rmidTextBox->Text;
		String^ rName = rmnameTextBox->Text;
		String^ iName = rminameTextBox->Text;
		String^ iCount = rmicountTextBox->Text;
		String^ iStock = getActiveStockCh();
		String^ iType = getActiveTypeCh();

		if (rID == "" || rName == "" || iName == "" || iCount == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(rID) || containsIllegal(rName) || containsIllegal(iName) || containsIllegal(iCount)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRM("+rID+", '"+rName+"', '"+iName+"', "+iCount+", '"+iStock+"', '"+iType+"')", con);


		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void rmidSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ rID = rmidTextBox->Text;

		if (rID == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(rID)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRMID(" + rID + ")", con);


		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void rmnameSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ rName = rmnameTextBox->Text;

		if (rName == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(rName)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRMName('" + rName + "')", con);


		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void rminameSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ iName = rminameTextBox->Text;

		if (iName == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(iName)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRMIName('" + iName + "')", con);


		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void rmicountSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ iCount = rmicountTextBox->Text;

		if (iCount == "") {
			MessageBox::Show("Empty fields.", "Notice:");
			return;
		}

		if (containsIllegal(iCount)) {
			MessageBox::Show("Input contains illegal characters.", "Notice:");
			return;
		}

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRMICnt(" + iCount + ")", con);


		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void rmstatusSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ iStatus = getActiveStockCh();

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRMStatus('" + iStatus + "')", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ iType = getActiveTypeCh();

		// Initiate procedure
		MySqlConnection^ con = gcnew MySqlConnection(conStr);
		MySqlDataAdapter^ sda = gcnew MySqlDataAdapter("CALL SearchRMType('" + iType + "')", con);

		// Update the table
		DataTable^ dt = gcnew DataTable();
		sda->Fill(dt);
		bindingSRC->DataSource = dt;
		dataGridView->DataSource = bindingSRC;
	}

	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message, "Error:");
	}
}
};
}
