#pragma once

#include "ViewTree.h"
#include "xApp.h"

class CClassToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

class xExplorer;

class xExplorerTree : public CViewTree
{
	DECLARE_MESSAGE_MAP()

public:
	xExplorerTree(xExplorer * explorer);
	~xExplorerTree();

protected:
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

protected:
	HTREEITEM mDragItem;
	CImageList * mDragImage;
	bool mDragging;
	int mDragTimer;
	xExplorer * mExplorer;
};

class xExplorer : public CDockablePane
{
	DECLARE_MESSAGE_MAP()

	struct Item
	{
		Item * parent;
		HTREEITEM hItem;
		TString128 name;
		bool floder;

		Array<Item*> children;
	};

public:
	xExplorer();
	virtual ~xExplorer();

	void AdjustLayout();
	void OnChangeVisualStyle();

protected:
	CClassToolBar m_wndToolBar;
	xExplorerTree mViewTree;
	CImageList mImages;
	UINT m_nCurrSort;

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	void _Init(void * param0, void * param1);
	void _UnloadScene(void * param0, void * param1);
	void _OnSerialize(void * param0, void * param1);
	void _AfterLoadScene(void * param0, void * param1);
	void _ObjCreated(void * param0, void * param1);

	void _SaveItem(Item & item, xSerializer & Serializer);
	void _LoadItem(Item & item, xSerializer & Serializer);

	void _CopyItem(HTREEITEM hDesItem, HTREEITEM hSrcItem);

protected:
	void _InsertItem(HTREEITEM hItem, Item & item);
	void _InitTreeView();
	Item * _getItem(HTREEITEM hItem);
	Item * _getItem(HTREEITEM hItem, Item & cItem);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnNewFolder();
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg LRESULT OnChangeActiveTab(WPARAM, LPARAM);
	afx_msg void OnSort(UINT id);
	afx_msg void OnUpdateSort(CCmdUI* pCmdUI);

protected:
	tEventListener<xExplorer> OnInit;
	tEventListener<xExplorer> OnUnloadScene;
	tEventListener<xExplorer> OnAfterLoadScene;
	tEventListener<xExplorer> OnSerialize;
	tEventListener<xExplorer> OnObjCreated;

	Map<TString128, int> mTypeIconMap;

	Array<Item*> mItems;
};

