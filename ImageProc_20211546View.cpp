
// ImageProc_20211546View.cpp: CImageProc20211546View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProc_20211546.h"
#endif

#include "ImageProc_20211546Doc.h"
#include "ImageProc_20211546View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProc20211546View

IMPLEMENT_DYNCREATE(CImageProc20211546View, CScrollView)

BEGIN_MESSAGE_MAP(CImageProc20211546View, CScrollView)
	ON_COMMAND(ID_PIXEL_ADD, &CImageProc20211546View::OnPixelAdd)
	ON_COMMAND(ID_PIXEL_SUB, &CImageProc20211546View::OnPixelSub)
	ON_COMMAND(ID_PIXEL_MUL, &CImageProc20211546View::OnPixelMul)
	ON_COMMAND(ID_PIXEL_DIV, &CImageProc20211546View::OnPixelDiv)
	ON_COMMAND(ID_PIXEL_HISTO_EQ, &CImageProc20211546View::OnPixelHistoEq)
	ON_COMMAND(ID_PIXEL_CONTRAST_STRECHING, &CImageProc20211546View::OnPixelContrastStreching)
	ON_COMMAND(ID_PIXEL_BINARIZATION, &CImageProc20211546View::OnPixelBinarization)
	ON_COMMAND(ID_PIXEL_TWO_IMAGE_ADD, &CImageProc20211546View::OnPixelTwoImageAdd)
	ON_COMMAND(ID_PIXEL_TWO_IMAGE_SUB, &CImageProc20211546View::OnPixelTwoImageSub)
	ON_COMMAND(ID_REGION_SMOOTHING, &CImageProc20211546View::OnRegionSmoothing)
	ON_COMMAND(ID_REGION_SHARPENING, &CImageProc20211546View::OnRegionSharpening)
	ON_COMMAND(ID_REGION_EMBOSING, &CImageProc20211546View::OnRegionEmbosing)
	ON_COMMAND(ID_REGION_PREWITT, &CImageProc20211546View::OnRegionPrewitt)
	ON_COMMAND(ID_REGION_SOBEL, &CImageProc20211546View::OnRegionSobel)
	ON_COMMAND(ID_REGION_ROBERTS, &CImageProc20211546View::OnRegionRoberts)
	ON_COMMAND(ID_REGION_AVERAGE_FILTERING, &CImageProc20211546View::OnRegionAverageFiltering)
	ON_COMMAND(ID_REGION_MEDIAN_FILTERING, &CImageProc20211546View::OnRegionMedianFiltering)
	ON_COMMAND(ID_MOPOLOGY_COLOR_GRAY, &CImageProc20211546View::OnMopologyColorGray)
	ON_COMMAND(ID_MOPOLOGY_BINARIZATION, &CImageProc20211546View::OnMopologyBinarization)
	ON_COMMAND(ID_MOPOLOGY_EROSION, &CImageProc20211546View::OnMopologyErosion)
	ON_COMMAND(ID_MOPOLOGY_OPENING, &CImageProc20211546View::OnMopologyOpening)
	ON_COMMAND(ID_MOPOLOGY_DILATION, &CImageProc20211546View::OnMopologyDilation)
	ON_COMMAND(ID_MOPOLOGY_CLOSING, &CImageProc20211546View::OnMopologyClosing)
	ON_COMMAND(ID_GEOMETRY_ZOOMIN_PIXEL_COPY, &CImageProc20211546View::OnGeometryZoominPixelCopy)
	ON_COMMAND(ID_GEOMETRY_ZOOMIN_BILINAR_INTEPOLATION, &CImageProc20211546View::OnGeometryZoominBilinarIntepolation)
	ON_COMMAND(ID_GEOMETRY_ZOOMOUT_SUBSAMPLING, &CImageProc20211546View::OnGeometryZoomoutSubsampling)
	ON_COMMAND(ID_GEOMETRY_ZOOMOUT_SUBSAMPLING_MEAN_SUB, &CImageProc20211546View::OnGeometryZoomoutSubsamplingMeanSub)
	ON_COMMAND(ID_GEOMETRY_AVG_FILTERING, &CImageProc20211546View::OnGeometryAvgFiltering)
	ON_COMMAND(ID_GEOMETRY_ROTATION, &CImageProc20211546View::OnGeometryRotation)
END_MESSAGE_MAP()

// CImageProc20211546View 생성/소멸

CImageProc20211546View::CImageProc20211546View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProc20211546View::~CImageProc20211546View()
{
}

BOOL CImageProc20211546View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CImageProc20211546View 그리기

void CImageProc20211546View::OnDraw(CDC* pDC)
{
	CImageProc20211546Doc* pDoc = GetDocument(); //view와 연결된 document
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int x, y;
	if (pDoc->InputImg != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel(x, y, RGB(pDoc->InputImg[y][x], pDoc->InputImg[y][x], pDoc->InputImg[y][x]));
		}

		else {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel(x, y, RGB(pDoc->InputImg[y][3 * x + 0], pDoc->InputImg[y][3 * x + 1], pDoc->InputImg[y][3 * x + 2]));
		}
	}

	if (pDoc->ResultImg != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel(pDoc->ImageWidth + 20 + x, y, RGB(pDoc->ResultImg[y][x], pDoc->ResultImg[y][x], pDoc->ResultImg[y][x]));
		}

		else {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel(pDoc->ImageWidth + 20 + x, y, RGB(pDoc->ResultImg[y][3 * x + 0], pDoc->ResultImg[y][3 * x + 1], pDoc->ResultImg[y][3 * x + 2]));
		}
	}

	if (pDoc->InputImg2 != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel(2 * (pDoc->ImageWidth + 20) + x, y, RGB(pDoc->InputImg2[y][x], pDoc->InputImg2[y][x], pDoc->InputImg2[y][x]));
		}
		else {
			for (y = 0; y < pDoc->ImageHeight; y++)
				for (x = 0; x < pDoc->ImageWidth; x++)
					pDC->SetPixel(2 * (pDoc->ImageWidth + 20) + x, y, RGB(pDoc->InputImg2[y][3 * x + 0], pDoc->InputImg2[y][3 * x + 1], pDoc->InputImg2[y][3 * x + 2]));
		}
	}

	//확대 축소(기하학적 처리) 이미지용
	if (pDoc->gResultImg != NULL) {
		if (pDoc->depth == 1) {
			for (y = 0; y < pDoc->gImageHeight; y++)
				for (x = 0; x < pDoc->gImageWidth; x++)
					pDC->SetPixel(x, pDoc->ImageHeight + 20 + y, RGB(pDoc->gResultImg[y][x], pDoc->gResultImg[y][x], pDoc->gResultImg[y][x]));
		}

		else if (pDoc->depth == 3) {
			for (y = 0; y < pDoc->gImageHeight; y++)
				for (x = 0; x < pDoc->gImageWidth; x++)
					pDC->SetPixel(x, pDoc->ImageHeight + 20 + y, RGB(pDoc->gResultImg[y][3 * x + 0], pDoc->gResultImg[y][3 * x + 1], pDoc->gResultImg[y][3 * x + 2]));
		}
	}


}

void CImageProc20211546View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 2048;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CImageProc20211546View 진단

#ifdef _DEBUG
void CImageProc20211546View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImageProc20211546View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImageProc20211546Doc* CImageProc20211546View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProc20211546Doc)));
	return (CImageProc20211546Doc*)m_pDocument;
}
#endif //_DEBUG


// CImageProc20211546View 메시지 처리기


void CImageProc20211546View::OnPixelAdd()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	if (pDoc->InputImg == NULL) return;

	int x, y, value;

	for(y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = pDoc->InputImg[y][x] + 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][x] = value;
			}
			else {
				value = pDoc->InputImg[y][3 * x + 0] + 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;
				value = pDoc->InputImg[y][3 * x + 1] + 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;
				value = pDoc->InputImg[y][3 * x + 2] + 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}
	Invalidate();
}


void CImageProc20211546View::OnPixelSub()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int x, y, value;

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = pDoc->InputImg[y][x] - 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][x] = value;
			}
			else {
				value = pDoc->InputImg[y][3 * x + 0] - 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;
				value = pDoc->InputImg[y][3 * x + 1] - 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;
				value = pDoc->InputImg[y][3 * x + 2] - 50;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}
	Invalidate();
}


void CImageProc20211546View::OnPixelMul()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int x, y, value;

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = pDoc->InputImg[y][x] * 1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][x] = value;
			}
			else {
				value = pDoc->InputImg[y][3 * x + 0] * 1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;
				value = pDoc->InputImg[y][3 * x + 1] * 1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;
				value = pDoc->InputImg[y][3 * x + 2] * 1.5;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}
	Invalidate();
}


void CImageProc20211546View::OnPixelDiv()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int x, y, value;

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = pDoc->InputImg[y][x] / 1.2;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][x] = value;
			}
			else {
				value = pDoc->InputImg[y][3 * x + 0] / 1.2;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;

				value = pDoc->InputImg[y][3 * x + 1] / 1.2;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;

				value = pDoc->InputImg[y][3 * x + 2] / 1.2;
				if (value > 255)
					value = 255;
				else if (value < 0)
					value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}
	Invalidate();
}


void CImageProc20211546View::OnPixelHistoEq()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int x, y, i, k;
	int acc_hist;
	int N = pDoc->ImageHeight * pDoc->ImageWidth; //화소의 개수
	int hist[256], sum[256]; //그대로 유지 (밝기 값이기 때문)
    
	//히스토그램 구하기
	for (i = 0; i < 256; i++) hist[i] = 0;
	
	for (y = 0; y <  pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			k = pDoc->InputImg[y][x];
			hist[k]++;
		}

	//누적분포 구하기: 밝기
	acc_hist = 0;
	for (i = 0; i < 256; i++) {
		acc_hist += hist[i];
		sum[i] = acc_hist;
	}

	//평활화 화소값 저장 -	변경 필요
	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				k = pDoc->InputImg[y][x];
				pDoc->ResultImg[y][x] = (float)sum[k] / N * 255;
			} //N or sum[k] 둘 중 하나 float 형태로 만들기 
			else {
				k = pDoc->InputImg[y][3 * x + 0];
				pDoc->ResultImg[y][3 * x + 0] = (float)sum[k] / N * 255;

				k = pDoc->InputImg[y][3 * x + 1];
				pDoc->ResultImg[y][3 * x + 1] = (float)sum[k] / N * 255;

				k = pDoc->InputImg[y][3 * x + 2];
				pDoc->ResultImg[y][3 * x + 2] = (float)sum[k] / N * 255;
			}
		}
	Invalidate();
}


void CImageProc20211546View::OnPixelContrastStreching()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int x, y, value;
	int min = 255, max = 0;

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				if (pDoc->InputImg[y][x] < min) min = pDoc->InputImg[y][x];
				if (pDoc->InputImg[y][x] > max) max = pDoc->InputImg[y][x];
			}
			else {
				if (pDoc->InputImg[y][3 * x + 0] < min) min = pDoc->InputImg[y][3 * x + 0];
				if (pDoc->InputImg[y][3 * x + 0] > max) max = pDoc->InputImg[y][3 * x + 0];

				if (pDoc->InputImg[y][3 * x + 1] < min) min = pDoc->InputImg[y][3 * x + 1];
				if (pDoc->InputImg[y][3 * x + 1] > max) max = pDoc->InputImg[y][3 * x + 1];

				if (pDoc->InputImg[y][3 * x + 2] < min) min = pDoc->InputImg[y][3 * x + 2];
				if (pDoc->InputImg[y][3 * x + 2] > max) max = pDoc->InputImg[y][3 * x + 2];
			}
		}

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = pDoc->InputImg[y][x];
				pDoc->ResultImg[y][x] = (float)(value - min) / (max - min) * 255;
			}
			else {
				value = pDoc->InputImg[y][3 * x + 0];
				pDoc->ResultImg[y][3 * x + 0] = (float)(value - min) / (max - min) * 255;

				value = pDoc->InputImg[y][3 * x + 1];
				pDoc->ResultImg[y][3 * x + 1] = (float)(value - min) / (max - min) * 255;

				value = pDoc->InputImg[y][3 * x + 2];
				pDoc->ResultImg[y][3 * x + 2] = (float)(value - min) / (max - min) * 255;
			}
		}

	Invalidate();
}


void CImageProc20211546View::OnPixelBinarization()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int x, y, value;
	int threshold = 150;

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = pDoc->InputImg[y][x];
				if (value >= threshold)
					pDoc->ResultImg[y][x] = 255;
				else
					pDoc->ResultImg[y][x] = 0;
			}
			else {
				value = pDoc->InputImg[y][3 * x + 0];
				if (value >= threshold)
					pDoc->ResultImg[y][3 * x + 0] = 255;
				else
					pDoc->ResultImg[y][3 * x + 0] = 0;

				value = pDoc->InputImg[y][3 * x + 1];
				if (value >= threshold)
					pDoc->ResultImg[y][3 * x + 1] = 255;
				else
					pDoc->ResultImg[y][3 * x + 1] = 0;

				value = pDoc->InputImg[y][3 * x + 2];
				if (value >= threshold)
					pDoc->ResultImg[y][3 * x + 2] = 255;
				else
					pDoc->ResultImg[y][3 * x + 2] = 0;
			}
		}
	Invalidate();
}


void CImageProc20211546View::OnPixelTwoImageAdd()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	CFileDialog dlg(TRUE);

	if (dlg.DoModal() != IDOK)
		return;
	
	CFile file;
	file.Open(dlg.GetPathName(), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	pDoc->LoadSecondImageFile(ar);
	file.Close();
	//LoadTwoImage();

	int x, y, value;

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			value = 0.7 * pDoc->InputImg[y][x] + 0.3 * pDoc->InputImg2[y][x];
			if (value > 255)
				value = 255;
			else if (value < 0)
				value = 0;
			pDoc->ResultImg[y][x] = value;
		}
	Invalidate();
}


void CImageProc20211546View::LoadTwoImage()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	CFileDialog dlg(TRUE);

	if (dlg.DoModal() == IDOK) {
		CFile file;
		file.Open(dlg.GetPathName(), CFile::modeRead);
		file.Read(pDoc->InputImg2, 256 * 256);
		file.Close();
	}
}


void CImageProc20211546View::OnPixelTwoImageSub()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	CFileDialog dlg(TRUE);

	if (dlg.DoModal() != IDOK)
		return;

	CFile file;
	file.Open(dlg.GetPathName(), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	pDoc->LoadSecondImageFile(ar);
	file.Close();
	//LoadTwoImage();

	int x, y, value;

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			value = abs(pDoc->InputImg[y][x] - pDoc->InputImg2[y][x]);
			if (value > 64)
				value = 255;
			else
				value = 0;
			pDoc->ResultImg[y][x] = value;
		}
	Invalidate();
}


void CImageProc20211546View::OnRegionSmoothing()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	float kernel[3][3] = { {1.0 / 9,1.0 / 9 ,1.0 / 9},
						   {1.0 / 9,1.0 / 9 ,1.0 / 9},
						   {1.0 / 9,1.0 / 9 ,1.0 / 9} };
	
	Convole(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, kernel, 0, pDoc->depth);
	
	Invalidate();
}


void CImageProc20211546View::Convole(unsigned char** InImg, unsigned char** OutImg, int cols, int rows, float mask[][3], int bias, int depth)
{
	int x, y, i, j;
	float sum, redsum, greensum, bluesum;

	for (y = 1; y < rows - 1; y++)
		for (x = 1; x < cols - 1; x++) {
			if (depth == 1) {
				sum = 0;
				for (j = 0; j < 3; j++)
					for (i = 0; i < 3; i++)
					{
						sum += InImg[y - 1 + j][x - 1 + i] * mask[j][i];
					}
				sum += bias;
				if (sum > 255) sum = 255;
				else if (sum < 0) sum = 0;
				OutImg[y][x] = sum;
			}
			else {
				redsum = 0;
				greensum = 0;
				bluesum = 0;
				for (j = 0; j < 3; j++)
					for (i = 0; i < 3; i++)
					{
						redsum += InImg[y - 1 + j][3 * (x - 1 + i) + 0] * mask[j][i];
						greensum += InImg[y - 1 + j][3 * (x - 1 + i) + 1] * mask[j][i];
						bluesum += InImg[y - 1 + j][3 * (x - 1 + i) + 2] * mask[j][i];
					}
				redsum += bias;
				greensum += bias;
				bluesum += bias;

				if (redsum > 255) redsum = 255;
				else if (redsum < 0) redsum = 0;
				if (greensum > 255) greensum = 255;
				else if (greensum < 0) greensum = 0;
				if (bluesum > 255) bluesum = 255;
				else if (bluesum < 0) bluesum = 0;

				OutImg[y][3 * x + 0] = redsum;
				OutImg[y][3 * x + 1] = greensum;
				OutImg[y][3 * x + 2] = bluesum;
			}
		}
}


void CImageProc20211546View::OnRegionSharpening()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	float kernel[3][3] = { {0,-1 ,0},
						   {-1, 5, -1},
						   {0, -1, 0} };

	Convole(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, kernel, 0, pDoc->depth);

	Invalidate();
}


void CImageProc20211546View::OnRegionEmbosing()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	float kernel[3][3] = { {-1, 0, 0},
						   {0, 0, 0},
						   {0, 0, 1} };

	Convole(pDoc->InputImg, pDoc->ResultImg, pDoc->ImageWidth, pDoc->ImageHeight, kernel, 128, pDoc->depth);

	Invalidate();
}


void CImageProc20211546View::OnRegionPrewitt()
{
	CImageProc20211546Doc* pDoc = GetDocument();
	
	float Hmask[3][3] = { {-1, -1, -1},
						  {0, 0, 0},
						  {1, 1, 1} };

	float Vmask[3][3] = { {1, 0, -1},
						  {1, 0, -1},
						  {1, 0, -1} };

	unsigned char** Er, ** Ec;
	int x, y, value;

	//메모리 할당
	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->ImageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}

	Convole(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, Hmask, 0, pDoc->depth);
	Convole(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, Vmask, 0, pDoc->depth);

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = sqrt(Er[y][x] * Er[y][x] + Ec[y][x] * Ec[y][x]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;
			}
			else {
				value = sqrt(Er[y][3 * x + 0] * Er[y][3 * x + 0] + Ec[y][3 * x + 0] * Ec[y][3 * x + 0]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;

				value = sqrt(Er[y][3 * x + 1] * Er[y][3 * x + 1] + Ec[y][3 * x + 1] * Ec[y][3 * x + 1]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;

				value = sqrt(Er[y][3 * x + 2] * Er[y][3 * x + 2] + Ec[y][3 * x + 2] * Ec[y][3 * x + 2]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;

				value = sqrt(pDoc->ResultImg[y][3 * x + 0] * pDoc->ResultImg[y][3 * x + 0]
					+ pDoc->ResultImg[y][3 * x + 1] * pDoc->ResultImg[y][3 * x + 1]
					+ pDoc->ResultImg[y][3 * x + 2] * pDoc->ResultImg[y][3 * x + 2]);

				if (value > 255)    value = 255;
				else if (value < 0) value = 0;

				pDoc->ResultImg[y][3 * x + 0] = value;
				pDoc->ResultImg[y][3 * x + 1] = value;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}

	//메모리 해제
	for (int i = 0; i < pDoc->ImageHeight; i++){
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);
	
	Invalidate();
}


void CImageProc20211546View::OnRegionSobel()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	float Hmask[3][3] = { {-1, -2, -1},
						  {0, 0, 0},
						  {1, 2, 1} };

	float Vmask[3][3] = { {1, 0, -1},
						  {2, 0, -2},
						  {1, 0, -1} };

	unsigned char** Er, ** Ec;
	int x, y, value;

	//메모리 할당
	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->ImageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}

	Convole(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, Hmask, 0, pDoc->depth);
	Convole(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, Vmask, 0, pDoc->depth);

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = sqrt(Er[y][x] * Er[y][x] + Ec[y][x] * Ec[y][x]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;
			}
			else {
				value = sqrt(Er[y][3 * x + 0] * Er[y][3 * x + 0] + Ec[y][3 * x + 0] * Ec[y][3 * x + 0]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;

				value = sqrt(Er[y][3 * x + 1] * Er[y][3 * x + 1] + Ec[y][3 * x + 1] * Ec[y][3 * x + 1]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;

				value = sqrt(Er[y][3 * x + 2] * Er[y][3 * x + 2] + Ec[y][3 * x + 2] * Ec[y][3 * x + 2]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;

				
				value = sqrt(pDoc->ResultImg[y][3 * x + 0] * pDoc->ResultImg[y][3 * x + 0]
					+ pDoc->ResultImg[y][3 * x + 1] * pDoc->ResultImg[y][3 * x + 1]
					+ pDoc->ResultImg[y][3 * x + 2] * pDoc->ResultImg[y][3 * x + 2]);

				if (value > 255)    value = 255;
				else if (value < 0) value = 0;

				pDoc->ResultImg[y][3 * x + 0] = value;
				pDoc->ResultImg[y][3 * x + 1] = value;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}

	//메모리 해제
	for (int i = 0; i < pDoc->ImageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CImageProc20211546View::OnRegionRoberts()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	float Hmask[3][3] = { {-1, 0, 0},
						  {0, 1, 0},
						  {0, 0, 0} };

	float Vmask[3][3] = { {0, 0, -1},
						  {0, 1, 0},
						  {0, 0, 0} };

	unsigned char** Er, ** Ec;
	int x, y, value;

	//메모리 할당
	Er = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	Ec = (unsigned char**)malloc(pDoc->ImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->ImageHeight; i++) {
		Er[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
		Ec[i] = (unsigned char*)malloc(pDoc->ImageWidth * pDoc->depth);
	}

	Convole(pDoc->InputImg, Er, pDoc->ImageWidth, pDoc->ImageHeight, Hmask, 0, pDoc->depth);
	Convole(pDoc->InputImg, Ec, pDoc->ImageWidth, pDoc->ImageHeight, Vmask, 0, pDoc->depth);

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				value = sqrt(Er[y][x] * Er[y][x] + Ec[y][x] * Ec[y][x]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][x] = value;
			}
			else {
				value = sqrt(Er[y][3 * x + 0] * Er[y][3 * x + 0] + Ec[y][3 * x + 0] * Ec[y][3 * x + 0]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 0] = value;

				value = sqrt(Er[y][3 * x + 1] * Er[y][3 * x + 1] + Ec[y][3 * x + 1] * Ec[y][3 * x + 1]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 1] = value;

				value = sqrt(Er[y][3 * x + 2] * Er[y][3 * x + 2] + Ec[y][3 * x + 2] * Ec[y][3 * x + 2]);
				if (value > 255)    value = 255;
				else if (value < 0) value = 0;
				pDoc->ResultImg[y][3 * x + 2] = value;

				value = sqrt(pDoc->ResultImg[y][3 * x + 0] * pDoc->ResultImg[y][3 * x + 0]
					+ pDoc->ResultImg[y][3 * x + 1] * pDoc->ResultImg[y][3 * x + 1]
					+ pDoc->ResultImg[y][3 * x + 2] * pDoc->ResultImg[y][3 * x + 2]);

				if (value > 255)    value = 255;
				else if (value < 0) value = 0;

				pDoc->ResultImg[y][3 * x + 0] = value;
				pDoc->ResultImg[y][3 * x + 1] = value;
				pDoc->ResultImg[y][3 * x + 2] = value;
			}
		}

	//메모리 해제
	for (int i = 0; i < pDoc->ImageHeight; i++) {
		free(Er[i]);
		free(Ec[i]);
	}
	free(Er);
	free(Ec);

	Invalidate();
}


void CImageProc20211546View::OnRegionAverageFiltering()
{
	CImageProc20211546Doc* pDoc = GetDocument();
	int x, y, i, j;
	int xcor, ycor;
	int sum, rsum, gsum, bsum, count;

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth; x++) {
			if (pDoc->depth == 1) {
				sum = 0;
				count = 0;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						ycor = y + j;
						xcor = x + i;

						//영역 넘어가는 테두리 부분 확인
						if (0 <= ycor && ycor <= pDoc->ImageHeight - 1 && 0 <= xcor && xcor <= pDoc->ImageWidth - 1) {
							sum += pDoc->InputImg[ycor][xcor];
							count++;
						}
						//if문으로 영역 내부 값만 더함
					}

				pDoc->ResultImg[y][x] = sum / count;
			}
			else {
				rsum = gsum = bsum = 0;
				count = 0;
				for (j = -2; j <= 2; j++)
					for (i = -2; i <= 2; i++) {
						ycor = y + j;
						xcor = x + i;

						//영역 넘어가는 테두리 부분 확인
						if (0 <= ycor && ycor <= pDoc->ImageHeight - 1 && 0 <= xcor && xcor <= pDoc->ImageWidth - 1) {
							rsum += pDoc->InputImg[ycor][3 * xcor + 0];
							gsum += pDoc->InputImg[ycor][3 * xcor + 1];
							bsum += pDoc->InputImg[ycor][3 * xcor + 2];
							count++;
						}
						//if문으로 영역 내부 값-테두리 제외-만 더함
					}

				pDoc->ResultImg[y][3 * x + 0] = rsum / count;
				pDoc->ResultImg[y][3 * x + 1] = gsum / count;
				pDoc->ResultImg[y][3 * x + 2] = bsum / count;
			}
			
		}
	Invalidate();
}


void CImageProc20211546View::OnRegionMedianFiltering()
{
	CImageProc20211546Doc* pDoc = GetDocument();
	int x, y, i, j, temp;
	int n[9];

	for (y = 1; y < pDoc->ImageHeight - 1; y++)
		for (x = 1; x < pDoc->ImageWidth - 1; x++) {
			if (pDoc->depth == 1) {
				n[0] = pDoc->InputImg[y - 1][x - 1];
				n[1] = pDoc->InputImg[y - 1][x - 0];
				n[2] = pDoc->InputImg[y - 1][x + 1];

				n[3] = pDoc->InputImg[y - 0][x - 1];
				n[4] = pDoc->InputImg[y - 0][x - 0];
				n[5] = pDoc->InputImg[y - 0][x + 1];

				n[6] = pDoc->InputImg[y + 1][x - 1];
				n[7] = pDoc->InputImg[y + 1][x - 0];
				n[8] = pDoc->InputImg[y + 1][x + 1];

				//sorting(정렬법)
				for (i = 8; i > 0; i--)
					for (j = 0; j < i; j++)
						if (n[j] > n[j + 1]) {
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
				pDoc->ResultImg[y][x] = n[4];
			}
			else {
				n[0] = pDoc->InputImg[y - 1][3 * (x - 1) + 0];
				n[1] = pDoc->InputImg[y - 1][3 * (x - 0) + 0];
				n[2] = pDoc->InputImg[y - 1][3 * (x + 1) + 0];

				n[3] = pDoc->InputImg[y - 0][3 * (x - 1) + 0];
				n[4] = pDoc->InputImg[y - 0][3 * (x - 0) + 0];
				n[5] = pDoc->InputImg[y - 0][3 * (x + 1) + 0];

				n[6] = pDoc->InputImg[y + 1][3 * (x - 1) + 0];
				n[7] = pDoc->InputImg[y + 1][3 * (x - 0) + 0];
				n[8] = pDoc->InputImg[y + 1][3 * (x + 1) + 0];

				//sorting(정렬법)
				for (i = 8; i > 0; i--)
					for (j = 0; j < i; j++)
						if (n[j] > n[j + 1]) {
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
				pDoc->ResultImg[y][3 * x + 0] = n[4];

				n[0] = pDoc->InputImg[y - 1][3 * (x - 1) + 1];
				n[1] = pDoc->InputImg[y - 1][3 * (x - 0) + 1];
				n[2] = pDoc->InputImg[y - 1][3 * (x + 1) + 1];

				n[3] = pDoc->InputImg[y - 0][3 * (x - 1) + 1];
				n[4] = pDoc->InputImg[y - 0][3 * (x - 0) + 1];
				n[5] = pDoc->InputImg[y - 0][3 * (x + 1) + 1];

				n[6] = pDoc->InputImg[y + 1][3 * (x - 1) + 1];
				n[7] = pDoc->InputImg[y + 1][3 * (x - 0) + 1];
				n[8] = pDoc->InputImg[y + 1][3 * (x + 1) + 1];

				//sorting(정렬법)
				for (i = 8; i > 0; i--)
					for (j = 0; j < i; j++)
						if (n[j] > n[j + 1]) {
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
				pDoc->ResultImg[y][3 * x + 1] = n[4];

				n[0] = pDoc->InputImg[y - 1][3 * (x - 1) + 2];
				n[1] = pDoc->InputImg[y - 1][3 * (x - 0) + 2];
				n[2] = pDoc->InputImg[y - 1][3 * (x + 1) + 2];

				n[3] = pDoc->InputImg[y - 0][3 * (x - 1) + 2];
				n[4] = pDoc->InputImg[y - 0][3 * (x - 0) + 2];
				n[5] = pDoc->InputImg[y - 0][3 * (x + 1) + 2];

				n[6] = pDoc->InputImg[y + 1][3 * (x - 1) + 2];
				n[7] = pDoc->InputImg[y + 1][3 * (x - 0) + 2];
				n[8] = pDoc->InputImg[y + 1][3 * (x + 1) + 2];

				//sorting(정렬법)
				for (i = 8; i > 0; i--)
					for (j = 0; j < i; j++)
						if (n[j] > n[j + 1]) {
							temp = n[j + 1];
							n[j + 1] = n[j];
							n[j] = temp;
						}
				pDoc->ResultImg[y][3 * x + 2] = n[4];
			}
		}
	Invalidate();
}


void CImageProc20211546View::OnMopologyColorGray()
{
	CImageProc20211546Doc* pDoc = GetDocument();
	
	if (pDoc->depth == 1) 
		return;

	int x, y;
	int gray;

	for (y = 0; y < pDoc->ImageHeight - 1; y++)
		for (x = 0; x < pDoc->ImageWidth - 1; x++) {
			gray = (pDoc->InputImg[y][3 * x + 0] + pDoc->InputImg[y][3 * x + 1] + pDoc->InputImg[y][3 * x + 2]) / 3;
			
			pDoc->InputImg[y][3 * x + 0] = gray;
			pDoc->InputImg[y][3 * x + 1] = gray;
			pDoc->InputImg[y][3 * x + 2] = gray;
		}
	Invalidate();
}


void CImageProc20211546View::OnMopologyBinarization()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int x, y;
	int thresh = 128;

	for (y = 0; y < pDoc->ImageHeight - 1; y++)
		for (x = 0; x < pDoc->ImageWidth - 1; x++) {
			if (pDoc->depth == 1) {
				if (pDoc->InputImg[y][x] > thresh)
					pDoc->InputImg[y][x] = 255;
				else
					pDoc->InputImg[y][x] = 0;
			}
			else {
				if ((pDoc->InputImg[y][3 * x + 0] 
					+ pDoc->InputImg[y][3 * x + 1] 
					+ pDoc->InputImg[y][3 * x + 2]) / 3
					> thresh) {
					pDoc->InputImg[y][3 * x + 0] = 255;
					pDoc->InputImg[y][3 * x + 1] = 255;
					pDoc->InputImg[y][3 * x + 2] = 255;
				}
				else {
					pDoc->InputImg[y][3 * x + 0] = 0;
					pDoc->InputImg[y][3 * x + 1] = 0;
					pDoc->InputImg[y][3 * x + 2] = 0;
				}
			}
		}
	Invalidate();
}

//침식 연산
void CImageProc20211546View::OnMopologyErosion()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int x, y, i, j;
	int min, rmin, gmin, bmin = 255;
	
	for (y = 1; y < pDoc->ImageHeight - 1; y++)
		for (x = 1; x < pDoc->ImageWidth - 1; x++) 
		{
			if (pDoc->depth == 1) {
				min = 255;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						if (pDoc->InputImg[y + j][x + i] < min)
							min = pDoc->InputImg[y + j][x + i];
					}
				pDoc->ResultImg[y][x] = min;
			}
			else {
				rmin = 255; gmin = 255; bmin = 255;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						if (pDoc->InputImg[y + j][3 * (x + i) + 0] < rmin)
							rmin = pDoc->InputImg[y + j][3 * (x + i) + 0];

						if (pDoc->InputImg[y + j][3 * (x + i) + 1] < gmin)
							gmin = pDoc->InputImg[y + j][3 * (x + i) + 1];

						if (pDoc->InputImg[y + j][3 * (x + i) + 2] < bmin)
							bmin = pDoc->InputImg[y + j][3 * (x + i) + 2];
					}
				pDoc->ResultImg[y][3 * x + 0] = rmin;
				pDoc->ResultImg[y][3 * x + 1] = gmin;
				pDoc->ResultImg[y][3 * x + 2] = bmin;
			}
		}
	Invalidate();
}

//팽창 연산
void CImageProc20211546View::OnMopologyDilation()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int x, y, i, j;
	int max, rmax, gmax, bmax = 0;

	for (y = 1; y < pDoc->ImageHeight - 1; y++)
		for (x = 1; x < pDoc->ImageWidth - 1; x++)
		{
			if (pDoc->depth == 1) {
				max = 0;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						if (pDoc->InputImg[y + j][x + i] > max)
							max = pDoc->InputImg[y + j][x + i];
					}
				pDoc->ResultImg[y][x] = max;
			}
			else {
				rmax = 0; gmax = 0; bmax = 0;
				for (j = -1; j <= 1; j++)
					for (i = -1; i <= 1; i++) {
						if (pDoc->InputImg[y + j][3 * (x + i) + 0] > rmax)
							rmax = pDoc->InputImg[y + j][3 * (x + i) + 0];

						if (pDoc->InputImg[y + j][3 * (x + i) + 1] > gmax)
							gmax = pDoc->InputImg[y + j][3 * (x + i) + 1];

						if (pDoc->InputImg[y + j][3 * (x + i) + 2] > bmax)
							bmax = pDoc->InputImg[y + j][3 * (x + i) + 2];
					}
				pDoc->ResultImg[y][3 * x + 0] = rmax;
				pDoc->ResultImg[y][3 * x + 1] = gmax;
				pDoc->ResultImg[y][3 * x + 2] = bmax;
			}
		}
	Invalidate();
}


void CImageProc20211546View::CopyResultToInput()
{
	CImageProc20211546Doc* pDoc = GetDocument();
	int x, y;

	for (y = 0; y < pDoc->ImageHeight; y++)
		for (x = 0; x < pDoc->ImageWidth * pDoc->depth; x++)
		{
			pDoc->InputImg[y][x] = pDoc->ResultImg[y][x];
		}
}

//선 침식
void CImageProc20211546View::OnMopologyOpening()
{
	
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();

	CopyResultToInput();
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();

	Invalidate();
}


void CImageProc20211546View::OnMopologyClosing()
{
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();
	CopyResultToInput();
	OnMopologyDilation();

	CopyResultToInput();
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();
	CopyResultToInput();
	OnMopologyErosion();

	Invalidate();
}


void CImageProc20211546View::OnGeometryZoominPixelCopy()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int xscale = 3;
	int yscale = 2;
	int x, y;

	//기존 메모리 제거
	if (pDoc->gResultImg != NULL) 
	{
		for (int i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->ImageWidth * xscale;
	pDoc->gImageHeight = pDoc->ImageHeight * yscale;

	// 메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gImageHeight; i++) {
		
		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}
	for (y = 0; y < pDoc->gImageHeight; y++)
		for (x = 0; x < pDoc->gImageWidth; x++)
		{
			if (pDoc->depth == 1) {
				pDoc->gResultImg[y][x] = pDoc->InputImg[y / yscale][x / xscale];
			}
			else {
				pDoc->gResultImg[y][3 * x + 0] = pDoc->InputImg[y / yscale][3 * (x / xscale) + 0];
				pDoc->gResultImg[y][3 * x + 1] = pDoc->InputImg[y / yscale][3 * (x / xscale) + 1];
				pDoc->gResultImg[y][3 * x + 2] = pDoc->InputImg[y / yscale][3 * (x / xscale) + 2];
			}
		}
	//전방향 사상
	/*
	for (y = 0; y = pDoc->gImageHeight; y++)
		for (x = 0; x = pDoc->gImageWidth; x++)
		{
			pDoc->gResultImg[y * yscale][x * xscale] = pDoc->InputImg[y][x];
		}
		*/
	Invalidate();
}


void CImageProc20211546View::OnGeometryZoominBilinarIntepolation()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int x, y;

	float xscale = 2.3;
	float yscale = 1.5;
	float src_x, src_y;
	float alpha, beta;
	int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	int E, F;

	// 메모리 제거
	if (pDoc->gResultImg != NULL)
	{
		for (int i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->ImageWidth * xscale + 0.5;
	pDoc->gImageHeight = pDoc->ImageHeight * yscale + 0.5;

	// 메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gImageHeight; i++) {

		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	//역방향 사상
	for (y = 0; y < pDoc->gImageHeight; y++)
		for (x = 0; x < pDoc->gImageWidth; x++)
		{
			src_x = x / xscale;
			src_y = y / yscale;
			alpha = src_x - (int)src_x;
			beta = src_y - (int)src_y;

			Ax = (int)src_x;
			Ay = (int)src_y;

			Bx = Ax + 1;
			By = Ay;

			Cx = Ax;
			Cy = Ay + 1;

			Dx = Ax + 1;
			Dy = Ay + 1;

			if (Bx > pDoc->ImageWidth - 1) Bx = pDoc->ImageWidth - 1;
			if (Cy > pDoc->ImageHeight - 1) Cy = pDoc->ImageHeight - 1;
			if (Dx > pDoc->ImageWidth - 1) Dx = pDoc->ImageWidth - 1;
			if (Dy > pDoc->ImageHeight - 1) Dy = pDoc->ImageHeight - 1;


			if (pDoc->depth == 1) {
				E = (1 - alpha) * pDoc->InputImg[Ay][Ax] + alpha * pDoc->InputImg[By][Bx];
				F = (1 - alpha) * pDoc->InputImg[Cy][Cx] + alpha * pDoc->InputImg[Dy][Dx];
				pDoc->gResultImg[y][x] = (1 - beta) * E + beta * F;
			}
			else {
				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 0] + alpha * pDoc->InputImg[By][3 * Bx + 0];
				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 0] + alpha * pDoc->InputImg[Dy][3 * Dx + 0];
				pDoc->gResultImg[y][3 * x + 0] = (1 - beta) * E + beta * F;

				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 1] + alpha * pDoc->InputImg[By][3 * Bx + 1];
				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 1] + alpha * pDoc->InputImg[Dy][3 * Dx + 1];
				pDoc->gResultImg[y][3 * x + 1] = (1 - beta) * E + beta * F;

				E = (1 - alpha) * pDoc->InputImg[Ay][3 * Ax + 2] + alpha * pDoc->InputImg[By][3 * Bx + 2];
				F = (1 - alpha) * pDoc->InputImg[Cy][3 * Cx + 2] + alpha * pDoc->InputImg[Dy][3 * Dx + 2];
				pDoc->gResultImg[y][3 * x + 2] = (1 - beta) * E + beta * F;
			}

			
		}
	
	Invalidate();
}


void CImageProc20211546View::OnGeometryZoomoutSubsampling()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int xscale = 3; // 1/3의 값
	int yscale = 2; // 1/2의 값

	int x, y;


	if (pDoc->gResultImg != NULL)
	{
		for (int i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->ImageWidth / xscale;
	pDoc->gImageHeight = pDoc->ImageHeight / yscale;

	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gImageHeight; i++) {

		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	//역방향 사상
	for (y = 0; y < pDoc->gImageHeight; y++)
		for (x = 0; x < pDoc->gImageWidth; x++)
		{
			if (pDoc->depth == 1) {
				pDoc->gResultImg[y][x] = pDoc->InputImg[y * yscale][x * xscale];
			}
			else {
				pDoc->gResultImg[y][3 * x + 0] = pDoc->InputImg[y * yscale][3 * (x * xscale) + 0];
				pDoc->gResultImg[y][3 * x + 1] = pDoc->InputImg[y * yscale][3 * (x * xscale) + 1];
				pDoc->gResultImg[y][3 * x + 2] = pDoc->InputImg[y * yscale][3 * (x * xscale) + 2];
			}
		}
	Invalidate();

}


void CImageProc20211546View::OnGeometryZoomoutSubsamplingMeanSub()
{
	OnRegionSmoothing();
	CopyResultToInput();
	OnGeometryZoomoutSubsampling();

	Invalidate();
}


void CImageProc20211546View::OnGeometryAvgFiltering()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	int xscale = 3; // 1/3의 값
	int yscale = 2; // 1/2의 값

	int x, y, i, j;
	int sum, rsum, gsum, bsum;
	int src_x, src_y;


	if (pDoc->gResultImg != NULL)
	{
		for (int i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->ImageWidth / xscale;
	pDoc->gImageHeight = pDoc->ImageHeight / yscale;

	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gImageHeight; i++) {

		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	//전방향 사상
	for (y = 0; y < pDoc->ImageHeight; y += yscale)
		for (x = 0; x < pDoc->ImageWidth; x += xscale)
		{
			if (pDoc->depth == 1)
			{
				sum = 0;
				for (j = 0; j < yscale; j++)
					for (i = 0; i < xscale; i++)
					{
						src_x = x + i;
						src_y = y + j;

						sum += pDoc->InputImg[src_y][src_x];
					}
				pDoc->gResultImg[y / yscale][x / xscale] = sum / (xscale * yscale);
			}
			else {
				rsum = 0; 
				gsum = 0; 
				bsum = 0;

				for (j = 0; j < yscale; j++)
					for (i = 0; i < xscale; i++)
					{
						src_x = x + i;
						src_y = y + j;

						rsum += pDoc->InputImg[src_y][3 * src_x + 0];
						gsum += pDoc->InputImg[src_y][3 * src_x + 1];
						bsum += pDoc->InputImg[src_y][3 * src_x + 2];
					}
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 0] = rsum / (xscale * yscale);
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 1] = gsum / (xscale * yscale);
				pDoc->gResultImg[y / yscale][3 * (x / xscale) + 2] = bsum / (xscale * yscale);
			}
		}
	Invalidate();
}

#define PI 3.1415926521

#include "CAngleDialog.h"

void CImageProc20211546View::OnGeometryRotation()
{
	CImageProc20211546Doc* pDoc = GetDocument();

	CAngleDialog dlg;

	int angle = -45; // 회전 각도: degree 단위
	float radian; // 각도 > radian으로 변환
	int Hy;
	int Cx, Cy;
	int x, y, xdiff, ydiff; // 밖으로 나온 영역 처리
	int x_source, y_source; 

	dlg.m_IAngle = angle; // default 값 설정
	//다이얼로그 화면 출력
	if (dlg.DoModal() == IDCANCEL) return;
	angle = dlg.m_IAngle;

	radian = PI / 180 * angle;

	// y좌표의 마지막 위치
	Hy = pDoc->ImageHeight - 1;

	// 영상 중심점
	Cx = pDoc->ImageWidth / 2;
	Cy = pDoc->ImageHeight / 2;

	if (pDoc->gResultImg != NULL)
	{
		for (int i = 0; i < pDoc->gImageHeight; i++)
			free(pDoc->gResultImg[i]);
		free(pDoc->gResultImg);
	}

	pDoc->gImageWidth = pDoc->ImageHeight * fabs(cos(PI / 2 - radian)) + pDoc->ImageWidth * fabs(cos(radian));
	pDoc->gImageHeight = pDoc->ImageHeight * fabs(cos(radian)) + pDoc->ImageWidth * fabs(cos(PI / 2 - radian));

	// 메모리 할당
	pDoc->gResultImg = (unsigned char**)malloc(pDoc->gImageHeight * sizeof(unsigned char*));
	for (int i = 0; i < pDoc->gImageHeight; i++) {

		pDoc->gResultImg[i] = (unsigned char*)malloc(pDoc->gImageWidth * pDoc->depth);
	}

	xdiff = (pDoc->gImageWidth - pDoc->ImageWidth) / 2;
	ydiff = (pDoc->gImageHeight - pDoc->ImageHeight) / 2;

	for (y = -ydiff; y < pDoc->gImageHeight - ydiff; y++)
		for (x = -xdiff; x < pDoc->gImageWidth - xdiff; x++)
		{
			x_source = (Hy - y - Cx) * sin(radian) + (x - Cx) * cos(radian) + Cx;
			y_source = Hy - ((Hy - y - Cy) * cos(radian) - (x - Cx) * sin(radian) + Cy);

			if (pDoc->depth == 1) {
				if (x_source < 0 || x_source > pDoc->ImageWidth - 1 || y_source < 0 || y_source > pDoc->ImageHeight - 1)
					pDoc->gResultImg[y + ydiff][x + xdiff] = 255;
				else
					pDoc->gResultImg[y + ydiff][x + xdiff] = pDoc->InputImg[y_source][x_source];
			}
			else {
				if (x_source < 0 || x_source > pDoc->ImageWidth - 1 || y_source < 0 || y_source > pDoc->ImageHeight - 1)
				{
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 0] = 255;
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 1] = 255;
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 2] = 255;
				}
				else
				{
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 0] = pDoc->InputImg[y_source][3 * (x_source) + 0];
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 1] = pDoc->InputImg[y_source][3 * (x_source) + 1];
					pDoc->gResultImg[y + ydiff][3 * (x + xdiff) + 2] = pDoc->InputImg[y_source][3 * (x_source) + 2];
				}

			}

		}

	Invalidate();
}
