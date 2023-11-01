
// ImageProc_20211546Doc.h: CImageProc20211546Doc 클래스의 인터페이스
//


#pragma once


class CImageProc20211546Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImageProc20211546Doc() noexcept;
	DECLARE_DYNCREATE(CImageProc20211546Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CImageProc20211546Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	unsigned char **InputImg; //[y][x] -> input: 입력 영상을 위함
	unsigned char **InputImg2;
	unsigned char **ResultImg; // 영상 처리 결과 저장

	int ImageWidth;
	int ImageHeight;
	int depth; //흑백: 1 / 칼라: 3 저장

	int gImageWidth;
	int gImageHeight; //기하학적 처리를 위한 이미지 길이

	unsigned char** gResultImg; //기하학적 처리 저장용

	void LoadImageFile(CArchive& ar);
	void LoadSecondImageFile(CArchive& ar);
};
