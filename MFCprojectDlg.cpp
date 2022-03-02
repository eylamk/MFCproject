
#include "stdafx.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
	, Area(0)
	, Perimeter(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}
void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_COMBO1, comboLineWidth);
	DDX_CBString(pDX, IDC_COMBO1, lineWidthString);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, LineColorButton);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON1, lineC);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON3, FillColorButton);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON3, fillC);
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, Area);
	DDX_Text(pDX, IDC_EDIT3, Perimeter);
	DDX_Control(pDX, IDC_BUTTON7, SquareBtn);
	DDX_Control(pDX, IDC_BUTTON6, RecBtn);
	DDX_Control(pDX, IDC_BUTTON8, CircleBtn);
	DDX_Control(pDX, IDC_BUTTON9, EllipseBtn);
	DDX_Control(pDX, IDC_BUTTON10, RhombusBtn);
	DDX_Control(pDX, IDC_BUTTON11, SegmentBtn);
	DDX_Control(pDX, IDC_BUTTON5, ClearBtn);
	DDX_Control(pDX, IDCANCEL, CancelBtn);
	DDX_Control(pDX, IDC_BUTTON1, SaveBtn);
	DDX_Control(pDX, IDC_BUTTON2, LoadBtn);
	DDX_Control(pDX, IDC_BUTTON3, RemoveBtn);
	DDX_Control(pDX, IDC_BUTTON4, ResizeBtn);
}
BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCprojectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CMFCprojectDlg::OnBnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON3, &CMFCprojectDlg::OnBnClickedMfccolorbutton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCprojectDlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCprojectDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCprojectDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCprojectDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCprojectDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCprojectDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCprojectDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCprojectDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCprojectDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCprojectDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDCANCEL, &CMFCprojectDlg::OnBnClickedCancel)
END_MESSAGE_MAP()
BOOL CMFCprojectDlg::OnInitDialog() //Intialization
{
	CDialogEx::OnInitDialog();

	SetImages();
	CWnd::GetClientRect(&windowRect);
	paintArea.SetRect(windowRect.left+180 , windowRect.top + 70, windowRect.right - 6, windowRect.bottom - 5);
	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);		
	SetImages();
	CString t;
	for (int i = 1; i < 10; i++) {
		t.Format(_T("%d"), i);
		comboLineWidth.AddString(t);
	}
	comboLineWidth.SetCurSel(0);
	lineWidth = 1;
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CMFCprojectDlg::SetImages() { //IconsFunction

	HICON rectangle = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON4),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON ellipse = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON6),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON circle = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON5),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON segment = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON8),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON  square = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON  rhombus = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON7),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON  clear = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON10),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON  cancel = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON9),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON  resize = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON11),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON  load = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON12),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON  save = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON13),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);
	HICON  remove = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON14),
		IMAGE_ICON, 30, 30, LR_DEFAULTCOLOR);

	EllipseBtn.SetIcon(ellipse);
	RecBtn.SetIcon(rectangle);
	CircleBtn.SetIcon(circle);
	SegmentBtn.SetIcon(segment);
	SquareBtn.SetIcon(square);
	RhombusBtn.SetIcon(rhombus);
	ClearBtn.SetIcon(clear);
	CancelBtn.SetIcon(cancel);
	ResizeBtn.SetIcon(resize);
	LoadBtn.SetIcon(load);
	SaveBtn.SetIcon(save);
	RemoveBtn.SetIcon(remove);
}
void CMFCprojectDlg::OnPaint() //DrawFunction
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
		CPaintDC dc(this);// device context for painting
		CBrush bGcolor(RGB(255, 255, 255));
		dc.SelectObject(&bGcolor);
		dc.Rectangle(paintArea);
		CPoint a(windowRect.left+180,windowRect.top+ 70);
		CPoint b(windowRect.right - 6, windowRect.bottom - 5);
		mainR = new RectangleF(a, b, lineC, fillC, lineWidth);
		for (int i = 0; i < figs.GetSize(); i++) {
			if (mainR->isInside(figs[i]->P1)&& mainR->isInside(figs[i]->P2)) {
				figs[i]->Draw(&dc);

			}
		}
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CMFCprojectDlg::OnLButtonDown(UINT nFlags, CPoint point) //OnLButtonDown
{
	int size = figs.GetSize();
	start = point;
	isPressed = true;
	switch (future_Figure_Action)
	{
	case 1:
		figs.Add(new RectangleF(start, start,lineC,fillC,lineWidth));
		break;
	case 2:
		 figs.Add(new EllipseF(start, start, lineC, fillC, lineWidth));
		break;
	case 3:
		figs.Add(new SquareF(start, start, lineC, fillC, lineWidth));
		break;
	case 4:
		figs.Add(new RhombusF(start, start, lineC, fillC, lineWidth));
		break;
	case 5:
		figs.Add(new CircleF(start, start, lineC, fillC, lineWidth));
		break;
	case 6:
		figs.Add(new SegmentF(start, start, lineC, fillC, lineWidth));
		break;
	case -1: //Remove
		for (int i =0; i < size; i++) 
		{
			if (figs[i]->isInside(start)) {
				delete figs[i];
				figs.RemoveAt(i);
				InvalidateRect(paintArea);
				break;
			}	
		}
		break;
	case -2: //Resize
		for (int i = 0; i <size; i++)
		{
			if (figs[i]->isInside(start)) {
				resizeFig= figs[i];
				resize = true;
				resizeFig->Redefine(resizeFig->P1, point);
				Area = 0;
				Perimeter = 0;
				UpdateData(FALSE);
				break;
			}
		}
		break;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}
void CMFCprojectDlg::OnLButtonUp(UINT nFlags, CPoint point)//OnLButtonUp
{
	
	if (isPressed)
	{
		end = point;
		isPressed = false;
		if (resize)
		{
			resize = false;
			resizeFig->Redefine(resizeFig->P1, end);
		}
		else if (future_Figure_Action >=0) 
			figs[figs.GetSize() - 1]->Redefine(start, end); 

		InvalidateRect(paintArea); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}
void CMFCprojectDlg::OnMouseMove(UINT nFlags, CPoint point) //OnMouseMove
{
	if (isPressed)
	{
		end = point;
		if (resize) {
			resizeFig->Redefine(resizeFig->P1, point);
			Area = resizeFig->getArea();
			Perimeter = resizeFig->getPerimeter();
			UpdateData(FALSE);
		}
		else if (future_Figure_Action>=0){
			figs[figs.GetSize() - 1]->Redefine(start, end); // Changing the new figure
			Area = figs[figs.GetSize() - 1]->getArea();
			Perimeter = figs[figs.GetSize() - 1]->getPerimeter();
			UpdateData(FALSE);
		}
		InvalidateRect(paintArea); //simulates the WM_PAINT message to redraw window
	}
	CDialogEx::OnMouseMove(nFlags, point);
}
void CMFCprojectDlg::OnBnClickedButton1() //SaveButton
{

	             // FALSE to SAVE
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}
void CMFCprojectDlg::OnBnClickedButton2() //LoadButton
{
			     // TRUE to LOAD
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		InvalidateRect(paintArea);
	}

}
void CMFCprojectDlg::OnBnClickedMfccolorbutton1() //LineColor
{
	lineC = LineColorButton.GetColor();
} 
void CMFCprojectDlg::OnBnClickedMfccolorbutton3() //FillColor
{
	fillC = FillColorButton.GetColor();
}
void CMFCprojectDlg::OnCbnSelchangeCombo1() //LineWidth
{
	comboLineWidth.GetLBText(comboLineWidth.GetCurSel(), lineWidthString);
	lineWidth = _wtoi(lineWidthString);
	UpdateData(FALSE);
}
void CMFCprojectDlg::OnEnChangeEdit2(){} //Area
void CMFCprojectDlg::OnEnChangeEdit3(){} //Perimeter
void CMFCprojectDlg::OnBnClickedButton3() //RemoveFigure
{
	future_Figure_Action = -1;
}
void CMFCprojectDlg::OnBnClickedButton4() //ResizeFigure
{
	future_Figure_Action = -2;
}
void CMFCprojectDlg::OnBnClickedButton5() //ClearAll
{
	int size = figs.GetSize();
	for (int i = 0; i < size; i++)
	{
			delete figs[0];
			figs.RemoveAt(0);
	}
	InvalidateRect(paintArea);
	future_Figure_Action = 1;
	Area = 0;
	Perimeter = 0;
	UpdateData(FALSE);
}
void CMFCprojectDlg::OnBnClickedButton6() // Rectangle
{
	future_Figure_Action = 1;
}
void CMFCprojectDlg::OnBnClickedButton9() // Ellipse
{
	future_Figure_Action = 2;
}
void CMFCprojectDlg::OnBnClickedButton7() // Square
{
	future_Figure_Action = 3;
}
void CMFCprojectDlg::OnBnClickedButton10() // Rhombus
{
	future_Figure_Action = 4;
}
void CMFCprojectDlg::OnBnClickedButton8() // Circle
{
	future_Figure_Action = 5;
}
void CMFCprojectDlg::OnBnClickedButton11() //Segment
{
	future_Figure_Action = 6;
}
void CMFCprojectDlg::OnBnClickedCancel() //Cancel
{
	CDialogEx::OnCancel();
}


