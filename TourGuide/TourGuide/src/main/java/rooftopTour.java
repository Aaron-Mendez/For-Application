/*
    This is an addon to the decorator class that can be added
 */

/**
 *
 * @author aaron
 */
public class rooftopTour extends addOn {

    public rooftopTour(Tour newTour)
    {
        super(newTour);
    }
    @Override
    public String getDescription()
    {
        return tempTour.getDescription() + " A tour of rooftops and balconies";
    }
    
    @Override
    public double getCost()
    {
        return tempTour.getCost() + 25;
    } 
    
    @Override
    public int getMinTimeInMinutes()
    {
        return tempTour.getMinTimeInMinutes() + 60;
    } 
}
