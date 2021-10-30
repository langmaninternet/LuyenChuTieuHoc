
// HoTroFont4HangLuyenVietChuDlg.h : header file
//

#pragma once


// CHoTroFont4HangLuyenVietChuDlg dialog
class CHoTroFont4HangLuyenVietChuDlg : public CDialogEx
{
// Construction
public:
	CHoTroFont4HangLuyenVietChuDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOTROFONT4HANGLUYENVIETCHU_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void			Convert();
	afx_msg void OnBnClickedOk();

	afx_msg void OnEnChangeInput();
	CString m_decode;
};
