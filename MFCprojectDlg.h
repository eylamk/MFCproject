
// MFCprojectDlg.h : header file
#pragma once

#include "Figure.h"
#include "RectangleF.h"
#include "EllipseF.h"
#include "SquareF.h"
#include "RhombusF.h"
#include "CircleF.h"
#include "SegmentF.h"
#include <string.h>
#include <string>
using namespace std;
class CMFCprojectDlg : public CDialogEx
{
protected:
	virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV support
	void SetImages(); //OnInitDialog, adding icons to buttons.
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);// standard constructor
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif
	CPoint start, end; //Defined two points the start point and the end point.
	bool isPressed = false; //Indicates if the mouse is clicked.
	bool resize = false; //Indicates if resize mode is checked.
	CTypedPtrArray< CObArray, Figure*> figs; // An array contains all the figures drawed.
	Figure* resizeFig = NULL; // A pointer to the figure which will be resized.
	Figure* mainR; // The size of the main rectangle in which a user can draw.
	RECT windowRect; //Client's Window.
	CRect paintArea; //The white rectangle the user can paint in.
	int future_Figure_Action = 1; //(1 - Rectangle) (2 - Ellipse) (3 - Square) (4 - Rhombus) (5 - Circle) (6 - Segment) (-1 - remove) (-2 - resize)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1(); //SaveButton
	afx_msg void OnBnClickedButton2(); //LoadButton
	afx_msg void OnBnClickedMfccolorbutton1();//LineColor
	afx_msg void OnBnClickedMfccolorbutton3();//FillColor
	afx_msg void OnCbnSelchangeCombo1();//LineWidth
	CMFCColorButton LineColorButton;
	COLORREF lineC;
	CMFCColorButton FillColorButton;
	COLORREF fillC;
	CComboBox comboLineWidth;
	CString lineWidthString;
	int lineWidth;
	CBrush defaultBrush;
	double Area;
	double Perimeter;
	afx_msg void OnEnChangeEdit2(); //Area
	afx_msg void OnEnChangeEdit3(); //Perimeter
	afx_msg void OnBnClickedButton3();//RemoveFigure
	afx_msg void OnBnClickedButton4();//ResizeFigure
	afx_msg void OnBnClickedButton5();//ClearAll
	afx_msg void OnBnClickedCancel();//Cancel
	CButton SquareBtn;
	CButton RecBtn;
	CButton CircleBtn;
	CButton EllipseBtn;
	CButton RhombusBtn;
	CButton SegmentBtn;
	CButton ClearBtn;
	afx_msg void OnBnClickedButton6(); //RectangleBtn
	afx_msg void OnBnClickedButton7(); //SquareBtn
	afx_msg void OnBnClickedButton8(); //CircleBtn
	afx_msg void OnBnClickedButton9(); //EllipseBtn
	afx_msg void OnBnClickedButton10(); //RhombusBtn
	afx_msg void OnBnClickedButton11(); //SegmentBtn
	CButton CancelBtn;
	CButton SaveBtn;
	CButton LoadBtn;
	CButton RemoveBtn;
	CButton ResizeBtn;
};
