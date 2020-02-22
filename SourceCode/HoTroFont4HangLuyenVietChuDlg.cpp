﻿
// HoTroFont4HangLuyenVietChuDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "HoTroFont4HangLuyenVietChu.h"
#include "HoTroFont4HangLuyenVietChuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:


};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHoTroFont4HangLuyenVietChuDlg dialog



CHoTroFont4HangLuyenVietChuDlg::CHoTroFont4HangLuyenVietChuDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HOTROFONT4HANGLUYENVIETCHU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHoTroFont4HangLuyenVietChuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHoTroFont4HangLuyenVietChuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CHoTroFont4HangLuyenVietChuDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_INPUT, &CHoTroFont4HangLuyenVietChuDlg::OnEnChangeInput)
END_MESSAGE_MAP()


// CHoTroFont4HangLuyenVietChuDlg message handlers

BOOL CHoTroFont4HangLuyenVietChuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CFont font;

	font.CreateFont(
		40,                            // Height
		0,                             // Width
		0,                             // Escapement
		0,                             // Orientation
		FW_BOLD,                       // Weight
		FALSE,                         // Italic
		FALSE,                          // Underline
		0,                             // StrikeOut
		DEFAULT_CHARSET,                // CharSet
		OUT_DEFAULT_PRECIS,            // OutPrecision
		CLIP_DEFAULT_PRECIS,           // ClipPrecision
		DEFAULT_QUALITY,               // Quality
		DEFAULT_PITCH | FF_SWISS,      // PitchAndFamily
		L"HP001 4 hàng");                     // Facename

	auto m_out = GetDlgItem(IDC_OUTPUT);
	m_out->SetFont(&font, 1);

	//SetFont()
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHoTroFont4HangLuyenVietChuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHoTroFont4HangLuyenVietChuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHoTroFont4HangLuyenVietChuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHoTroFont4HangLuyenVietChuDlg::Convert()
{
	CString inputText;
	GetDlgItemTextW(IDC_INPUT, inputText);
	inputText = L" " + inputText + L" ";
	inputText.Replace(L",", L"| ");
	inputText.Replace(L"|", L",");
	inputText.Replace(L",  ", L", ");
	inputText.Replace(L" ,", L",");

	inputText.Replace(L"oon", L"ά");
	inputText.Replace(L"ooc", L"β");
	inputText.Replace(L"oóc", L"γ");
	inputText.Replace(L"oọc", L"ǭ");

	inputText.Replace(L"mi", L"ji");
	inputText.Replace(L"mì", L"jì");
	inputText.Replace(L"mị", L"jị");
	inputText.Replace(L"mỉ", L"jỉ");
	inputText.Replace(L"mí", L"jí");
	inputText.Replace(L"mĩ", L"jĩ");

	inputText.Replace(L" r", L" ς");
	inputText.Replace(L"oa", L"Ξ");
	inputText.Replace(L"oà", L"♦");
	inputText.Replace(L"oạ", L"Ĳ");
	inputText.Replace(L"oả", L"♪");
	inputText.Replace(L"oá", L"Ǩ");
	inputText.Replace(L"oã", L"♫");
	inputText.Replace(L"òa", L"ƣ");
	inputText.Replace(L"ọa", L"Ʀ");
	inputText.Replace(L"ỏa", L"Ƥ");
	inputText.Replace(L"óa", L"Ƣ");
	inputText.Replace(L"õa", L"ƥ");
	inputText.Replace(L"oă", L"ę");
	inputText.Replace(L"oằ", L"ż");
	inputText.Replace(L"oặ", L"Ǡ");
	inputText.Replace(L"oẳ", L"ſ");
	inputText.Replace(L"oắ", L"ĳ");
	inputText.Replace(L"oẵ", L"Ƌ");
	inputText.Replace(L"oc", L"Ο");
	inputText.Replace(L"ọc", L"ǌ");
	inputText.Replace(L"óc", L"ŉ");
	inputText.Replace(L"oi", L"Ρ");
	inputText.Replace(L"òi", L"ā");
	inputText.Replace(L"ọi", L"Ċ");
	inputText.Replace(L"ỏi", L"Ĉ");
	inputText.Replace(L"ói", L"Ā");
	inputText.Replace(L"õi", L"ĉ");
	inputText.Replace(L"om", L"Ψ");
	inputText.Replace(L"òm", L"ī");
	inputText.Replace(L"ọm", L"Į");
	inputText.Replace(L"ỏm", L"Ĭ");
	inputText.Replace(L"óm", L"Ī");
	inputText.Replace(L"õm", L"ĭ");
	inputText.Replace(L"on", L"Ϊ");
	inputText.Replace(L"òn", L"Ŝ");
	inputText.Replace(L"ọn", L"ŧ");
	inputText.Replace(L"ỏn", L"ŝ");
	inputText.Replace(L"ón", L"ŗ");
	inputText.Replace(L"õn", L"Ŧ");
	inputText.Replace(L"op", L"Φ");
	inputText.Replace(L"ọp", L"Ĥ");
	inputText.Replace(L"óp", L"ģ");
	inputText.Replace(L"ot", L"Τ");
	inputText.Replace(L"ọt", L"Ġ");
	inputText.Replace(L"ót", L"ĝ");
	inputText.Replace(L"ôc", L"″");
	inputText.Replace(L"ộc", L"ℓ");
	inputText.Replace(L"ốc", L"Ǭ");
	inputText.Replace(L"ôi", L"ċ");
	inputText.Replace(L"ồi", L"ē");
	inputText.Replace(L"ội", L"Ė");
	inputText.Replace(L"ổi", L"Ĕ");
	inputText.Replace(L"ối", L"Ē");
	inputText.Replace(L"ỗi", L"ĕ");
	inputText.Replace(L"ôm", L"į");
	inputText.Replace(L"ồm", L"ĵ");
	inputText.Replace(L"ộm", L"ĸ");
	inputText.Replace(L"ổm", L"Ķ");
	inputText.Replace(L"ốm", L"Ĵ");
	inputText.Replace(L"ỗm", L"ķ");
	inputText.Replace(L"ôn", L"Ū");
	inputText.Replace(L"ồn", L"Ŭ");
	inputText.Replace(L"ộn", L"ų");
	inputText.Replace(L"ổn", L"ŭ");
	inputText.Replace(L"ốn", L"ū");
	inputText.Replace(L"ỗn", L"Ų");
	inputText.Replace(L"ôp", L"Ļ");
	inputText.Replace(L"ộp", L"Ņ");
	inputText.Replace(L"ốp", L"ļ");
	inputText.Replace(L"ôt", L"Ō");
	inputText.Replace(L"ột", L"Ŏ");
	inputText.Replace(L"ốt", L"ō");
	inputText.Replace(L"ơc", L"έ");
	inputText.Replace(L"ợc", L"ϑ");
	inputText.Replace(L"ớc", L"ϐ");
	inputText.Replace(L"ơi", L"Π");
	inputText.Replace(L"ời", L"Ɵ");
	inputText.Replace(L"ợi", L"◦");
	inputText.Replace(L"ởi", L"▫");
	inputText.Replace(L"ới", L"ƞ");
	inputText.Replace(L"ỡi", L"ǫ");
	inputText.Replace(L"ơm", L"Χ");
	inputText.Replace(L"ờm", L"Ħ");
	inputText.Replace(L"ợm", L"ħ");
	inputText.Replace(L"ởm", L"ϕ");
	inputText.Replace(L"ớm", L"ĥ");
	inputText.Replace(L"ỡm", L"ϖ");
	inputText.Replace(L"ơn", L"Ω");
	inputText.Replace(L"ờn", L"Ŋ");
	inputText.Replace(L"ợn", L"Ŗ");
	inputText.Replace(L"ởn", L"ŋ");
	inputText.Replace(L"ớn", L"ņ");
	inputText.Replace(L"ỡn", L"ŏ");
	inputText.Replace(L"ơp", L"Υ");
	inputText.Replace(L"ợp", L"Ģ");
	inputText.Replace(L"ớp", L"ġ");
	inputText.Replace(L"ơt", L"Σ");
	inputText.Replace(L"ợt", L"Ĝ");
	inputText.Replace(L"ớt", L"ė");
	inputText.Replace(L"ơu", L"Ϋ");
	inputText.Replace(L"ơu", L"Ϋ");
	inputText.Replace(L"ợu", L"ŵ");
	inputText.Replace(L"ớu", L"Ŵ");








	// đuôi cao
	//		inputText.Replace(L"ie", L"Η΄");
	//		inputText.Replace(L"iè", L"Η˝");
	//		inputText.Replace(L"iẹ", L"Η−");
	//		inputText.Replace(L"iẻ", L"Η˞");
	//		inputText.Replace(L"ié", L"Η˛");
	//		inputText.Replace(L"iẽ", L"Ηˇ");
	//		inputText.Replace(L"iê", L"Ηł");
	//		inputText.Replace(L"iề", L"Ηϛ");
	//		inputText.Replace(L"iệ", L"Ηİ");
	//		inputText.Replace(L"iể", L"ΗϜ");
	//		inputText.Replace(L"iế", L"ΗĞ");
	//		inputText.Replace(L"iễ", L"Ηğ");

	//đuôi thấp
	inputText.Replace(L"ie", L"Η;");
	inputText.Replace(L"iè", L"Η∆");
	inputText.Replace(L"iẹ", L"Η");
	inputText.Replace(L"iẻ", L"Η◊");
	inputText.Replace(L"ié", L"Η≈");
	inputText.Replace(L"iẽ", L"Η⁄");
	inputText.Replace(L"iê", L"Η");
	inputText.Replace(L"iề", L"Ηˉ");
	inputText.Replace(L"iệ", L"ΗŃ");
	inputText.Replace(L"iể", L"Η˘");
	inputText.Replace(L"iế", L"Ηı");
	inputText.Replace(L"iễ", L"Η˙");





	inputText.Replace(L"ue", L"Μ;");
	inputText.Replace(L"uè", L"Μ∆");
	inputText.Replace(L"uẹ", L"Μ");
	inputText.Replace(L"uẻ", L"Μ◊");
	inputText.Replace(L"ué", L"Μ≈");
	inputText.Replace(L"uẽ", L"Μ⁄");
	inputText.Replace(L"uê", L"Μ");
	inputText.Replace(L"uề", L"Μˉ");
	inputText.Replace(L"uệ", L"ΜŃ");
	inputText.Replace(L"uể", L"Μ˘");
	inputText.Replace(L"uế", L"Μı");
	inputText.Replace(L"uễ", L"Μ˙");

	inputText.Replace(L"ye", L"ΐ;");
	inputText.Replace(L"yè", L"ΐ∆");
	inputText.Replace(L"yẹ", L"ΐ");
	inputText.Replace(L"yẻ", L"ΐ◊");
	inputText.Replace(L"yé", L"ΐ≈");
	inputText.Replace(L"yẽ", L"ΐ⁄");
	inputText.Replace(L"yê", L"ΐ");
	inputText.Replace(L"yề", L"ΐˉ");
	inputText.Replace(L"yệ", L"ΐŃ");
	inputText.Replace(L"yể", L"ΐ˘");
	inputText.Replace(L"yế", L"ΐı");
	inputText.Replace(L"yễ", L"ΐ˙");

	inputText.Replace(L"ghe", L"Ή;");
	inputText.Replace(L"ghè", L"Ή∆");
	inputText.Replace(L"ghẹ", L"Ή");
	inputText.Replace(L"ghẻ", L"Ή◊");
	inputText.Replace(L"ghé", L"Ή≈");
	inputText.Replace(L"ghẽ", L"Ή⁄");
	inputText.Replace(L"ghê", L"Ή");
	inputText.Replace(L"ghề", L"Ήˉ");
	inputText.Replace(L"ghệ", L"ΉŃ");
	inputText.Replace(L"ghể", L"Ή˘");
	inputText.Replace(L"ghế", L"Ήı");
	inputText.Replace(L"ghễ", L"Ή˙");
	inputText.Replace(L"Ghe", L"Ŷ;");
	inputText.Replace(L"Ghè", L"Ŷ∆");
	inputText.Replace(L"Ghẹ", L"Ŷ");
	inputText.Replace(L"Ghẻ", L"Ŷ◊");
	inputText.Replace(L"Ghé", L"Ŷ≈");
	inputText.Replace(L"Ghẽ", L"Ŷ⁄");
	inputText.Replace(L"Ghê", L"Ŷ");
	inputText.Replace(L"Ghề", L"Ŷˉ");
	inputText.Replace(L"Ghệ", L"ŶŃ");
	inputText.Replace(L"Ghể", L"Ŷ˘");
	inputText.Replace(L"Ghế", L"Ŷı");
	inputText.Replace(L"Ghễ", L"Ŷ˙");


	inputText.Replace(L"khe", L"Ά;");
	inputText.Replace(L"khè", L"Ά∆");
	inputText.Replace(L"khẹ", L"Ά");
	inputText.Replace(L"khẻ", L"Ά◊");
	inputText.Replace(L"khé", L"Ά≈");
	inputText.Replace(L"khẽ", L"Ά⁄");
	inputText.Replace(L"khê", L"Ά");
	inputText.Replace(L"khề", L"Άˉ");
	inputText.Replace(L"khệ", L"ΆŃ");
	inputText.Replace(L"khể", L"Ά˘");
	inputText.Replace(L"khế", L"Άı");
	inputText.Replace(L"khễ", L"Ά˙");


	inputText.Replace(L"nhe", L"·;");
	inputText.Replace(L"nhè", L"·∆");
	inputText.Replace(L"nhẹ", L"·");
	inputText.Replace(L"nhẻ", L"·◊");
	inputText.Replace(L"nhé", L"·≈");
	inputText.Replace(L"nhẽ", L"·⁄");
	inputText.Replace(L"nhê", L"·");
	inputText.Replace(L"nhề", L"·ˉ");
	inputText.Replace(L"nhệ", L"·Ń");
	inputText.Replace(L"nhể", L"·˘");
	inputText.Replace(L"nhế", L"·ı");
	inputText.Replace(L"nhễ", L"·˙");


	inputText.Replace(L"che", L"Έ;");
	inputText.Replace(L"chè", L"Έ∆");
	inputText.Replace(L"chẹ", L"Έ");
	inputText.Replace(L"chẻ", L"Έ◊");
	inputText.Replace(L"ché", L"Έ≈");
	inputText.Replace(L"chẽ", L"Έ⁄");
	inputText.Replace(L"chê", L"Έ");
	inputText.Replace(L"chề", L"Έˉ");
	inputText.Replace(L"chệ", L"ΈŃ");
	inputText.Replace(L"chể", L"Έ˘");
	inputText.Replace(L"chế", L"Έı");
	inputText.Replace(L"chễ", L"Έ˙");


	inputText.Replace(L"the", L"Ό;");
	inputText.Replace(L"thè", L"Ό∆");
	inputText.Replace(L"thẹ", L"Ό");
	inputText.Replace(L"thẻ", L"Ό◊");
	inputText.Replace(L"thé", L"Ό≈");
	inputText.Replace(L"thẽ", L"Ό⁄");
	inputText.Replace(L"thê", L"Ό");
	inputText.Replace(L"thề", L"Όˉ");
	inputText.Replace(L"thệ", L"ΌŃ");
	inputText.Replace(L"thể", L"Ό˘");
	inputText.Replace(L"thế", L"Όı");
	inputText.Replace(L"thễ", L"Ό˙");


	inputText.Replace(L"phe", L"Ί;");
	inputText.Replace(L"phè", L"Ί∆");
	inputText.Replace(L"phẹ", L"Ί");
	inputText.Replace(L"phẻ", L"Ί◊");
	inputText.Replace(L"phé", L"Ί≈");
	inputText.Replace(L"phẽ", L"Ί⁄");
	inputText.Replace(L"phê", L"Ί");
	inputText.Replace(L"phề", L"Ίˉ");
	inputText.Replace(L"phệ", L"ΊŃ");
	inputText.Replace(L"phể", L"Ί˘");
	inputText.Replace(L"phế", L"Ίı");
	inputText.Replace(L"phễ", L"Ί˙");


	

	inputText.Replace(L"he", L"Ǘ;");
	inputText.Replace(L"hè", L"Ǘ∆");
	inputText.Replace(L"hẹ", L"Ǘ");
	inputText.Replace(L"hẻ", L"Ǘ◊");
	inputText.Replace(L"hé", L"Ǘ≈");
	inputText.Replace(L"hẽ", L"Ǘ⁄");
	inputText.Replace(L"hê", L"Ǘ");
	inputText.Replace(L"hề", L"Ǘˉ");
	inputText.Replace(L"hệ", L"ǗŃ");
	inputText.Replace(L"hể", L"Ǘ˘");
	inputText.Replace(L"hế", L"Ǘı");
	inputText.Replace(L"hễ", L"Ǘ˙");
	inputText.Replace(L"He", L"υ;");
	inputText.Replace(L"Hè", L"υ∆");
	inputText.Replace(L"Hẹ", L"υ");
	inputText.Replace(L"Hẻ", L"υ◊");
	inputText.Replace(L"Hé", L"υ≈");
	inputText.Replace(L"Hẽ", L"υ⁄");
	inputText.Replace(L"Hê", L"υ");
	inputText.Replace(L"Hề", L"υˉ");
	inputText.Replace(L"Hệ", L"υŃ");
	inputText.Replace(L"Hể", L"υ˘");
	inputText.Replace(L"Hế", L"υı");
	inputText.Replace(L"Hễ", L"υ˙");

	inputText.Replace(L"le", L"Δ;");
	inputText.Replace(L"lè", L"Δ∆");
	inputText.Replace(L"lẹ", L"Δ");
	inputText.Replace(L"lẻ", L"Δ◊");
	inputText.Replace(L"lé", L"Δ≈");
	inputText.Replace(L"lẽ", L"Δ⁄");
	inputText.Replace(L"lê", L"Δ");
	inputText.Replace(L"lề", L"Δˉ");
	inputText.Replace(L"lệ", L"ΔŃ");
	inputText.Replace(L"lể", L"Δ˘");
	inputText.Replace(L"lế", L"Δı");
	inputText.Replace(L"lễ", L"Δ˙");
	inputText.Replace(L"Le", L"ϋ;");
	inputText.Replace(L"Lè", L"ϋ∆");
	inputText.Replace(L"Lẹ", L"ϋ");
	inputText.Replace(L"Lẻ", L"ϋ◊");
	inputText.Replace(L"Lé", L"ϋ≈");
	inputText.Replace(L"Lẽ", L"ϋ⁄");
	inputText.Replace(L"Lê", L"ϋ");
	inputText.Replace(L"Lề", L"ϋˉ");
	inputText.Replace(L"Lệ", L"ϋŃ");
	inputText.Replace(L"Lể", L"ϋ˘");
	inputText.Replace(L"Lế", L"ϋı");
	inputText.Replace(L"Lễ", L"ϋ˙");


	inputText.Replace(L"đe", L"Α;");
	inputText.Replace(L"đè", L"Α∆");
	inputText.Replace(L"đẹ", L"Α");
	inputText.Replace(L"đẻ", L"Α◊");
	inputText.Replace(L"đé", L"Α≈");
	inputText.Replace(L"đẽ", L"Α⁄");
	inputText.Replace(L"đê", L"Α");
	inputText.Replace(L"đề", L"Αˉ");
	inputText.Replace(L"đệ", L"ΑŃ");
	inputText.Replace(L"để", L"Α˘");
	inputText.Replace(L"đế", L"Αı");
	inputText.Replace(L"đễ", L"Α˙");


	//em
	inputText.Replace(L";m", L"΄m");
	inputText.Replace(L"∆m", L"˝m");
	inputText.Replace(L"m", L"−m");
	inputText.Replace(L"◊m", L"˞m");
	inputText.Replace(L"≈m", L"˛m");
	inputText.Replace(L"⁄m", L"ˇm");
	inputText.Replace(L"m", L"łm");
	inputText.Replace(L"ˉm", L"ϛm");
	inputText.Replace(L"Ńm", L"İm");
	inputText.Replace(L"˘m", L"Ϝm");
	inputText.Replace(L"ım", L"Ğm");
	inputText.Replace(L"˙m", L"ğm");
	inputText.Replace(L";n", L"΄n");
	inputText.Replace(L"∆n", L"˝n");
	inputText.Replace(L"n", L"−n");
	inputText.Replace(L"◊n", L"˞n");
	inputText.Replace(L"≈n", L"˛n");
	inputText.Replace(L"⁄n", L"ˇn");
	inputText.Replace(L"n", L"łn");
	inputText.Replace(L"ˉn", L"ϛn");
	inputText.Replace(L"Ńn", L"İn");
	inputText.Replace(L"˘n", L"Ϝn");
	inputText.Replace(L"ın", L"Ğn");
	inputText.Replace(L"˙n", L"ğn");
	inputText.Replace(L";p", L"΄p");
	inputText.Replace(L"∆p", L"˝p");
	inputText.Replace(L"p", L"−p");
	inputText.Replace(L"◊p", L"˞p");
	inputText.Replace(L"≈p", L"˛p");
	inputText.Replace(L"⁄p", L"ˇp");
	inputText.Replace(L"p", L"łp");
	inputText.Replace(L"ˉp", L"ϛp");
	inputText.Replace(L"Ńp", L"İp");
	inputText.Replace(L"˘p", L"Ϝp");
	inputText.Replace(L"ıp", L"Ğp");
	inputText.Replace(L"˙p", L"ğp");
	inputText.Replace(L";t", L"΄Ι");
	inputText.Replace(L"∆t", L"˝Ι");
	inputText.Replace(L"t", L"−Ι");
	inputText.Replace(L"◊t", L"˞Ι");
	inputText.Replace(L"≈t", L"˛Ι");
	inputText.Replace(L"⁄t", L"ˇΙ");
	inputText.Replace(L"t", L"łΙ");
	inputText.Replace(L"ˉt", L"ϛΙ");
	inputText.Replace(L"Ńt", L"İΙ");
	inputText.Replace(L"˘t", L"ϜΙ");
	inputText.Replace(L"ıt", L"ĞΙ");
	inputText.Replace(L"˙t", L"ğΙ");

	inputText.Replace(L";u", L"΄u");
	inputText.Replace(L"∆u", L"˝u");
	inputText.Replace(L"u", L"−u");
	inputText.Replace(L"◊u", L"˞u");
	inputText.Replace(L"≈u", L"˛u");
	inputText.Replace(L"⁄u", L"ˇu");
	inputText.Replace(L"u", L"łu");
	inputText.Replace(L"ˉu", L"ϛu");
	inputText.Replace(L"Ńu", L"İu");
	inputText.Replace(L"˘u", L"Ϝu");
	inputText.Replace(L"ıu", L"Ğu");
	inputText.Replace(L"˙u", L"ğu");



	inputText.Replace(L"eu", L"΄u");
	inputText.Replace(L"èu", L"˝u");
	inputText.Replace(L"ẹu", L"−u");
	inputText.Replace(L"ẻu", L"˞u");
	inputText.Replace(L"éu", L"˛u");
	inputText.Replace(L"ẽu", L"ˇu");
	inputText.Replace(L"êu", L"łu");
	inputText.Replace(L"ều", L"ϛu");
	inputText.Replace(L"ệu", L"İu");
	inputText.Replace(L"ểu", L"Ϝu");
	inputText.Replace(L"ếu", L"Ğu");
	inputText.Replace(L"ễu", L"ğu");
	inputText.Replace(L"t΄", L"Ι΄");
	inputText.Replace(L"t˝", L"Ι˝");
	inputText.Replace(L"t−", L"Ι−");
	inputText.Replace(L"t˞", L"Ι˞");
	inputText.Replace(L"t˛", L"Ι˛");
	inputText.Replace(L"tˇ", L"Ιˇ");
	inputText.Replace(L"tł", L"Ιł");
	inputText.Replace(L"tϛ", L"Ιϛ");
	inputText.Replace(L"tİ", L"Ιİ");
	inputText.Replace(L"tϜ", L"ΙϜ");
	inputText.Replace(L"tĞ", L"ΙĞ");
	inputText.Replace(L"tğ", L"Ιğ");
	inputText.Replace(L"gh", L"θ");
	inputText.Replace(L"kh", L"δ");
	inputText.Replace(L"nh", L"ζ");
	inputText.Replace(L"ch", L"ε");
	inputText.Replace(L"th", L"κ");
	inputText.Replace(L"ph", L"ι");
	inputText.Replace(L"tr", L"Λ");



	inputText.Replace(L"si", L"ǧ΅");
	inputText.Replace(L"sì", L"ǧŰ");
	inputText.Replace(L"sị", L"ǧŻ");
	inputText.Replace(L"sỉ", L"ǧű");
	inputText.Replace(L"sí", L"ǧť");
	inputText.Replace(L"sĩ", L"ǧź");
	inputText.Replace(L"sΗ", L"ǧμ");
	inputText.Replace(L"su", L"ǧί");
	inputText.Replace(L"sù", L"ǧǽ");
	inputText.Replace(L"sụ", L"ǧẀ");
	inputText.Replace(L"sủ", L"ǧǾ");
	inputText.Replace(L"sú", L"ǧǼ");
	inputText.Replace(L"sũ", L"ǧǿ");
	inputText.Replace(L"sư", L"ǧΰ");
	inputText.Replace(L"sừ", L"ǧẂ");
	inputText.Replace(L"sự", L"ǧẅ");
	inputText.Replace(L"sử", L"ǧẃ");
	inputText.Replace(L"sứ", L"ǧẁ");
	inputText.Replace(L"sữ", L"ǧẄ");

	inputText.Replace(L"vi", L"ν΅");
	inputText.Replace(L"vì", L"νŰ");
	inputText.Replace(L"vị", L"νŻ");
	inputText.Replace(L"vỉ", L"νű");
	inputText.Replace(L"ví", L"νť");
	inputText.Replace(L"vĩ", L"νź");
	inputText.Replace(L"vΗ", L"νμ");
	inputText.Replace(L"vu", L"νί");
	inputText.Replace(L"vù", L"νǽ");
	inputText.Replace(L"vụ", L"νẀ");
	inputText.Replace(L"vủ", L"νǾ");
	inputText.Replace(L"vú", L"νǼ");
	inputText.Replace(L"vũ", L"νǿ");
	inputText.Replace(L"vư", L"νΰ");
	inputText.Replace(L"vừ", L"νẂ");
	inputText.Replace(L"vự", L"νẅ");
	inputText.Replace(L"vử", L"νẃ");
	inputText.Replace(L"vứ", L"νẁ");
	inputText.Replace(L"vữ", L"νẄ");


	inputText.Replace(L"bi", L"λ΅");
	inputText.Replace(L"bì", L"λŰ");
	inputText.Replace(L"bị", L"λŻ");
	inputText.Replace(L"bỉ", L"λű");
	inputText.Replace(L"bí", L"λť");
	inputText.Replace(L"bĩ", L"λź");
	inputText.Replace(L"bΗ", L"λμ");
	inputText.Replace(L"bu", L"λί");
	inputText.Replace(L"bù", L"λǽ");
	inputText.Replace(L"bụ", L"λẀ");
	inputText.Replace(L"bủ", L"λǾ");
	inputText.Replace(L"bú", L"λǼ");
	inputText.Replace(L"bũ", L"λǿ");
	inputText.Replace(L"bư", L"λΰ");
	inputText.Replace(L"bừ", L"λẂ");
	inputText.Replace(L"bự", L"λẅ");
	inputText.Replace(L"bử", L"λẃ");
	inputText.Replace(L"bứ", L"λẁ");
	inputText.Replace(L"bữ", L"λẄ");

	inputText.Replace(L"qi", L"Ǖ΅");
	inputText.Replace(L"qì", L"ǕŰ");
	inputText.Replace(L"qị", L"ǕŻ");
	inputText.Replace(L"qỉ", L"Ǖű");
	inputText.Replace(L"qí", L"Ǖť");
	inputText.Replace(L"qĩ", L"Ǖź");
	inputText.Replace(L"qΗ", L"Ǖμ");
	inputText.Replace(L"qu", L"Ǖί");
	inputText.Replace(L"qù", L"Ǖǽ");
	inputText.Replace(L"qụ", L"ǕẀ");
	inputText.Replace(L"qủ", L"ǕǾ");
	inputText.Replace(L"qú", L"ǕǼ");
	inputText.Replace(L"qũ", L"Ǖǿ");
	inputText.Replace(L"qư", L"Ǖΰ");
	inputText.Replace(L"qừ", L"ǕẂ");
	inputText.Replace(L"qự", L"Ǖẅ");
	inputText.Replace(L"qử", L"Ǖẃ");
	inputText.Replace(L"qứ", L"Ǖẁ");
	inputText.Replace(L"qữ", L"ǕẄ");



	inputText.Replace(L" t", L" Ǉ");
	inputText.Replace(L" ζ", L" η");

	inputText.Replace(L" u ", L" Ď ");
	inputText.Replace(L" ư ", L" Ŕ ");
	inputText.Replace(L" u", L" Ď");
	inputText.Replace(L" ư", L" Ŕ");

	//3 chữ nh : η ζ ·
	// Các chữ mn : Ε Ζ   j w
	// u đặc biệt : Μ Μ


	SetDlgItemTextW(IDC_OUTPUT, inputText);
}
void CHoTroFont4HangLuyenVietChuDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	Convert();
}
void CHoTroFont4HangLuyenVietChuDlg::OnEnChangeInput()
{
	Convert();
}
