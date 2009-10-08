#ifndef _QDISPLAY_VIEWER_H_
#define _QDISPLAY_VIEWER_H_

#include <QGraphicsView>

#include <QMap>

namespace jafar {
namespace qdisplay {

class ImageView;
class Shape;
class Line;
class PolyLine;
/**
 * @ingroup qdisplay
 * This is the viewer, you can add ImageView to display on it, or overlay using Shape.
 */
class Viewer : public QGraphicsView {
  Q_OBJECT
  public:
    /**
     * Create a new viewer
     * @param mosaicWidth the width of one cell of the mosaic
     * @param mosaicHeight the height of one cell of the mosaic
     */
    Viewer(int mosaicWidth = 0, int mosaicHeight = 0, QGraphicsScene* scene = 0);
    
    ~Viewer();

    QGraphicsScene* scene() { return m_scene; }
    /**
     * @return the image item of cell (row,col)
     * @param row row number
     * @param col column number
     */
    ImageView* imageItem(int row = 0, int col = 0)
    {
      return m_imageMosaic[row][col];
    }
    /**
     * @param ii an ImageView to display on the scene.
     * @param row the number of the row in the mosaic
     * @param col the number of the column in the mosaic
     */
    void setImageView(ImageView* ii, int row = 0, int col= 0);
    int rows();
    int cols();
    /**
     * @param si a Shape to display on the scene.
     */
    void addShape(qdisplay::Shape* si);
    
    void splitVertical();
    void splitHorizontal();

    /**
     * @param si a Line to display on the scene.
     */
    void addLine(qdisplay::Line* li);

    void addPolyLine(qdisplay::PolyLine* pl);
    
    bool isVisible() { return !QGraphicsView::isHidden(); }
    /** Scale the view
     * @param scaleFactor the scale factor to appply to the view
     */
    void scaleView(qreal scaleFactor);
		/**
		 * Set the window size parameters
		 * @param width width of window
		 * @param height height of window
		 */
		void setWindowSize( int width, int height );
    /**
     * Close the view
     */
    void close();
    void setTitle(const std::string& _title );
  public slots:
    void exportView();
  public:
    /**
     * Export the view to the given file name.
     */
    void exportView( const std::string& fileName );
  protected:
    virtual void contextMenuEvent ( QContextMenuEvent * event );
    virtual void mouseReleaseEvent ( QMouseEvent * event );
    virtual void keyPressEvent ( QKeyEvent * event );
    virtual void wheelEvent(QWheelEvent *event);
  private:
    QGraphicsScene* m_scene;
    QMap< int, QMap< int, ImageView* > > m_imageMosaic;
    int m_mosaicWidth, m_mosaicHeight;
		int m_windowWidth, m_windowHeight;			// added
    double m_currentZ;
    QAction *m_exportView;
};

}
}

#endif
