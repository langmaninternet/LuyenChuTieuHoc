
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

	inputText.Replace(L",", L"| ");
	inputText.Replace(L"|", L",");
	inputText.Replace(L",  ", L", ");
	inputText.Replace(L" ,", L",");

	inputText.Replace(L"oon", L"ά");
	inputText.Replace(L"ooc", L"β");
	inputText.Replace(L"oọc", L"ǭ");
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
	inputText.Replace(L"ie", L"Η;");
	inputText.Replace(L"iè", L"Η˝");
	inputText.Replace(L"iẹ", L"Η");
	inputText.Replace(L"iẻ", L"Η˞");
	inputText.Replace(L"ié", L"Η˛");
	inputText.Replace(L"iẽ", L"Ηˇ");
	inputText.Replace(L"iê", L"Η");
	inputText.Replace(L"iề", L"Ηϛ");
	inputText.Replace(L"iệ", L"ΗŃ");
	inputText.Replace(L"iể", L"ΗϜ");
	inputText.Replace(L"iế", L"Ηı");
	inputText.Replace(L"iễ", L"Η˙");

	inputText.Replace(L"ue", L"Μ;");
	inputText.Replace(L"uè", L"Μ˝");
	inputText.Replace(L"uẹ", L"Μ");
	inputText.Replace(L"uẻ", L"Μ˞");
	inputText.Replace(L"ué", L"Μ˛");
	inputText.Replace(L"uẽ", L"Μˇ");
	inputText.Replace(L"uê", L"Μ");
	inputText.Replace(L"uề", L"Μϛ");
	inputText.Replace(L"uệ", L"ΜŃ");
	inputText.Replace(L"uể", L"ΜϜ");
	inputText.Replace(L"uế", L"Μı");
	inputText.Replace(L"uễ", L"Μ˙");

	
	inputText.Replace(L"gh", L"θ");
	inputText.Replace(L"kh", L"δ");
	inputText.Replace(L"nh", L"ζ");
	inputText.Replace(L"ch", L"ε");
	inputText.Replace(L"th", L"κ");
	inputText.Replace(L"ph", L"ι");

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
